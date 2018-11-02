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