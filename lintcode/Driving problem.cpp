//DFS time O(nlogn)
class Solution {
private:
    struct Obstacle {
        int m_x;
        int m_y;
        Obstacle() = default;
        Obstacle(int x, int y) : m_x(x), m_y(y) {}
    };

    struct ObstacleCompare {
        bool operator()(const Obstacle& o1, const Obstacle& o2) const {
            return o1.m_x * o1.m_x + o1.m_y*o1.m_y < o2.m_x * o2.m_x + o2.m_y*o2.m_y;
        }
    };

    bool isValid(const Obstacle& o, int W, int obstacleRadius, int carRadius) {
        return ((W - o.m_y) > (2 * carRadius + obstacleRadius)) || (o.m_y > (2 * carRadius + obstacleRadius));
    }

    bool obstaclesValid(const Obstacle& o1, const Obstacle& o2, int obstacleRadius, int carRadius) {
        double xDiff = o1.m_x - o2.m_x;
        double yDiff = o1.m_y - o2.m_y;
        return std::sqrt(xDiff * xDiff + yDiff * yDiff) > (2 * (obstacleRadius + carRadius));
    }

    bool dfs(const std::vector<Obstacle>& obstacles, int index, int lowerY, int upperY, int W) {
        if(index >= obstacles.size()) return true;

        if(lowerY == W && upperY == 0) {
            if(isValid(obstacles[index], W, 1, 2)) return dfs(obstacles, index + 1, obstacles[index].m_y - 1, obstacles[index].m_y + 1, W);
            else return false;
        } else {
            if(obstaclesValid(obstacles[index - 1], obstacles[index], 1, 2)) return dfs(obstacles, index + 1,  obstacles[index].m_y - 1, obstacles[index].m_y + 1, W);
            else {
                lowerY = std::min(obstacles[index].m_y - 1, lowerY);
                upperY = std::max(obstacles[index].m_y + 1, upperY);
                if(W - upperY > 4 || lowerY > 4) return  dfs(obstacles, index + 1,  lowerY, upperY, W);
                else return false;

            }
        }
    }
public:
    /**
     * @param L: the length
     * @param W: the width
     * @param p:  the obstacle coordinates
     * @return: yes or no
     */
    string drivingProblem(int L, int W, vector<vector<double>> &p) {
        std::vector<Obstacle> obstacles;
        for(auto o : p) {
            obstacles.push_back(Obstacle(o[0], o[1]));
        }

        std::sort(obstacles.begin(), obstacles.end(), ObstacleCompare());
        return dfs(obstacles, 0, W, 0, W) ? "yes" : "no";
    }
};


// Union Find Time O(n^2logn)
class Solution {
private:
    int m_fathers[1002] = {0};

    int find(int son) {
        if(son == m_fathers[son]) return son;
        m_fathers[son] = find(m_fathers[son]);
        return m_fathers[son];
    }

    void merge(int son1, int son2) {
        int father1 = find(son1);
        int father2 = find(son2);
        if(father1 != father2) {
            m_fathers[father2] = father1;
        }
    }

    double distance(double x1, double y1, double x2, double y2) {
        double xDiff = x1 - x2;
        double yDiff = y1 - y2;
        return std::sqrt(xDiff * xDiff + yDiff * yDiff);
    }

public:
    /**
     * @param L: the length
     * @param W: the width
     * @param p:  the obstacle coordinates
     * @return: yes or no
     */
    string drivingProblem(int L, int W, vector<vector<double>> &p) {
        int len = p.size();

        for(int i = 0; i < len + 2; ++i) {
            m_fathers[i] = i;
        }

        for(int i = 0; i < len; ++i) {
            for(int j = i + 1; j < len; ++j) {
                if(distance(p[i][0], p[i][1], p[j][0], p[j][1]) <= 6.0) merge(i, j);
            }
        }

        for(int i = 0; i < len; ++i) {
            if(p[i][1] <= 5.0) merge(len, i);
            if(W  - p[i][1] <= 5.0) merge(len + 1, i);
        }

        if (find(len) == find(len + 1)) return "no";
        return "yes";
    }
};