/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
private:
    struct CustomeHasher
    {
      size_t
      operator()(const Point & obj) const
      {
        return std::hash<int>()(obj.x) ^
                (std::hash<int>()(obj.y) << 1);
      }
    };
    struct CustomComparator
    {
      bool
      operator()(const Point & obj1, const Point & obj2) const
      {
        if (obj1.x == obj2.x && obj1.y == obj2.y)
          return true;
        return false;
      }
    };

    int m_islandNum = 0;
    std::unordered_map<Point, Point, CustomeHasher, CustomComparator> roots;
    int m_xMoves[4] = {-1, 0, 1, 0};
    int m_yMoves[4] = {0, 1, 0, -1};

    bool isValid(int n, int m, const Point& point) {
        return (-1 < point.x && point.x < n && -1 < point.y && point.y < m);
    }

    void unionMerge(const Point& first, const Point& second) {
        const Point& rootFirst = unionFind(first);
        const Point& rootSecond = unionFind(second);
        if(rootFirst.x != rootSecond.x || rootFirst.y != rootSecond.y) {
            roots[rootSecond] = rootFirst;
            --m_islandNum;
        }
    }

    Point unionFind(const Point& point) {
        if(roots[point].x == point.x && roots[point].y == point.y) return point;
        roots[point] = unionFind(roots[point]);
        return roots[point];
    }

public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        if(n == 0 || m == 0) return std::vector<int>(operators.size(), 0);
        if(operators.size() == 0) return std::vector<int>();

        std::vector<int> islandNums;
        for(const auto& point : operators) {
            if(roots.count(point) > 0) {
                islandNums.push_back(m_islandNum);
                continue;
            }
            ++m_islandNum;
            roots[point] = point;
            for(int i = 0; i < 4; ++i) {
                Point next(point.x + m_xMoves[i], point.y + m_yMoves[i]);
                if(!isValid(n, m, next)) continue;
                if(roots.count(next) == 0) continue;
                unionMerge(point, next);
            }
            islandNums.push_back(m_islandNum);
        }
        return islandNums;
    }
};