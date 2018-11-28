class Solution {
private:
    struct Pos{
        int m_x;
        int m_y;
        int m_step;
        Pos() = default;
        Pos(int x, int y, int step) : m_x(x), m_y(y), m_step(step) {}
    };

    vector<Pos> getNextMoves(const vector<vector<int>>& maze, const Pos& curr) {
        int rowSize = maze.size();
        int colSize = maze[0].size();

        int x = curr.m_x;
        int y = curr.m_y;

        vector<Pos> nextMoves;
        if(x > 0) {
            while(x > 0 && maze[x-1][y] == 0) {--x;}
            nextMoves.emplace_back(Pos(x, y, curr.m_step + curr.m_x - x));
        }
        x = curr.m_x;
        if(x < (rowSize - 1)) {
            while(x < (rowSize - 1) && maze[x+1][y] == 0) {++x;}
            nextMoves.emplace_back(Pos(x, y, curr.m_step + x - curr.m_x));
        }

        x = curr.m_x;
        if(y > 0) {
            while(y > 0 && maze[x][y-1] == 0) {--y;}
            nextMoves.emplace_back(Pos(x, y, curr.m_step + curr.m_y - y));
        }

        y = curr.m_y;
        if(y < (colSize-1)) {
            while(y < (colSize - 1) && maze[x][y+1] == 0) {++y;}
            nextMoves.emplace_back(Pos(x, y, curr.m_step + y - curr.m_y));
        }

        return nextMoves;
    }

    int getKey(int x, int y, int colSize) {
        return x * colSize + y;
    }
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: the shortest distance for the ball to stop at the destination
     */
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        int rowSize = maze.size();
        if(rowSize == 0) return -1;
        int colSize = maze[0].size();
        if(colSize == 0) return -1;

        queue<Pos> q;
        q.push(Pos(start[0], start[1], 0));
        unordered_set<int> visited;
        visited.insert(getKey(start[0], start[1], colSize));

        while(!q.empty()) {
            int len = q.size();
            while(len > 0) {
                auto curr = q.front();
                if(curr.m_x == destination[0] && curr.m_y == destination[1]) return curr.m_step;
                q.pop();
                const auto& nextMoves = getNextMoves(maze, curr);
                for(const auto& nextPos : nextMoves) {
                    if(visited.count(getKey(nextPos.m_x, nextPos.m_y, colSize))) continue;
                    q.push(nextPos);
                    visited.insert(getKey(nextPos.m_x, nextPos.m_y, colSize));
                }
                --len;
            }
        }

        return -1;
    }
};