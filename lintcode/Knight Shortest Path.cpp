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
    int m_xMoves[8] = {1, 1, -1, -1, 2, 2, -2, -2};
    int m_yMoves[8] = {2, -2, 2, -2, 1, -1, 1, -1};
/*
struct KeyHash {
 std::size_t operator()(const Point& k) const
 {
     return std::hash<int>()(k.x) ^
            (std::hash<int>()(k.y) << 1);
 }
};

struct KeyEqual {
 bool operator()(const Point& lhs, const Point& rhs) const
 {
    return lhs.x == rhs.x && lhs.y == rhs.y;
 }
};*/


    bool isValid(int rowLen, int colLen, const Point& next) {
        return (0 <= next.x && next.x < rowLen && 0 <= next.y && next.y < colLen);
    }
public:
    /**
     * @param grid: a chessboard included 0 (false) and 1 (true)
     * @param source: a point
     * @param destination: a point
     * @return: the shortest path
     */
    int shortestPath(vector<vector<bool>> &grid, Point &source, Point &destination) {
        // write your code here
        int rowLen = grid.size();
        if(rowLen == 0) return -1;
        int colLen = grid[0].size();
        if(colLen == 0) return -1;

        if(grid[source.x][source.y] == 1) return -1;

        std::queue<Point> q;
        q.push(source);
        grid[source.x][source.y] = 1;
        int steps = 0;
        while(!q.empty()) {
            int currentQSize = q.size();
            while (currentQSize > 0) {
                const auto& current = q.front();
                q.pop();
                if(current.x == destination.x && current.y == destination.y) return steps;
                for(int i = 0; i < 8; ++i) {
                    Point next(current.x + m_xMoves[i], current.y + m_yMoves[i]);
                    if(isValid(rowLen, colLen, next) && grid[next.x][next.y] == 0) {
                        grid[next.x][next.y] = 1;
                        q.push(next);
                    }
                }
                --currentQSize;
            }
            ++steps;
        }

        return -1;
    }
};