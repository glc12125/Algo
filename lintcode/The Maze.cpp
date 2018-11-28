class Solution {
private:
    struct Pos{
        int m_x;
        int m_y;
        Pos() = default;
        Pos(int x, int y) : m_x(x), m_y(y) {}
    };

    vector<Pos> getNextMoves(const vector<vector<int>>& maze, const Pos& curr) {
        int rowSize = maze.size();
        int colSize = maze[0].size();

        int x = curr.m_x;
        int y = curr.m_y;

        vector<Pos> nextMoves;
        if(x > 0) {
            while(x > 0 && maze[x-1][y] == 0) {--x;}
            nextMoves.emplace_back(Pos(x, y));
        }
        x = curr.m_x;
        if(x < (rowSize - 1)) {
            while(x < (rowSize - 1) && maze[x+1][y] == 0) {++x;}
            nextMoves.emplace_back(Pos(x, y));
        }

        x = curr.m_x;
        if(y > 0) {
            while(y > 0 && maze[x][y-1] == 0) {--y;}
            nextMoves.emplace_back(Pos(x, y));
        }

        y = curr.m_y;
        if(y < (colSize-1)) {
            while(y < (colSize - 1) && maze[x][y+1] == 0) {++y;}
            nextMoves.emplace_back(Pos(x, y));
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
     * @return: whether the ball could stop at the destination
     */
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        int rowSize = maze.size();
        if(rowSize == 0) return false;
        int colSize = maze[0].size();
        if(colSize == 0) return false;

        queue<Pos> q;
        q.push(Pos(start[0], start[1]));
        unordered_set<int> visited;
        visited.insert(getKey(start[0], start[1], colSize));

        while(!q.empty()) {
            auto curr = q.front();
            if(curr.m_x == destination[0] && curr.m_y == destination[1]) return true;
            q.pop();
            const auto& nextMoves = getNextMoves(maze, curr);
            for(const auto& nextPos : nextMoves) {
                if(visited.count(getKey(nextPos.m_x, nextPos.m_y, colSize))) continue;
                q.push(nextPos);
                visited.insert(getKey(nextPos.m_x, nextPos.m_y, colSize));
            }
        }

        return false;
    }
};