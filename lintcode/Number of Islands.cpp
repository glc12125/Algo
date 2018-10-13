class Solution{
private:
    int m_xMoves[4] = {-1, 0, 1, 0};
    int m_yMoves[4] = {0, 1, 0, -1};

    void bfs(std::vector<std::vector<bool> > &grid, int rowLen, int colLen, int i, int j) {
        std::queue<std::pair<int, int> > q;
        q.push(std::pair<int, int>(i, j));
        grid[i][j] = 0;
        while(!q.empty()) {
            auto pos = q.front();
            q.pop();
            for(int delta = 0; delta < 4; ++delta) {
                int nextX = pos.first + m_xMoves[delta];
                int nextY = pos.second + m_yMoves[delta];
                if(!isValid(rowLen, colLen, nextX, nextY) || grid[nextX][nextY] == 0) continue;
                q.push(std::pair<int, int>(nextX, nextY));
                grid[nextX][nextY] = 0;
            }
        }
    }

    bool isValid(int rowLen, int colLen, int i, int j) {
        return (0 <= i && i <= rowLen - 1 && 0 <= j && j <= colLen - 1);
    }

public:

    int numIslands(vector<vector<bool>> &grid) {
        int rowLen = grid.size();
        if(rowLen == 0) return 0;
        int colLen = grid[0].size();
        if(colLen == 0) return 0;

        int islandNum = 0;
        for(int i = 0; i < rowLen; ++i) {
            for(int j = 0; j < colLen; ++j) {
                if(grid[i][j] == 1) {
                    bfs(grid, rowLen, colLen, i, j);
                    ++islandNum;
                }
            }
        }
        return islandNum;
    }

};

// Union find solution to be added