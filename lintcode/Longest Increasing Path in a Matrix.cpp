// DFS, memoisation search, there is no need to record visited position, because we move in
// increasing direction
class Solution {
private:
    int m_xMoves[4] = {-1, 0, 1, 0};
    int m_yMoves[4] = {0, 1, 0, -1};

    bool isValidMove(int x, int y, int rowSize, int colSize) {
        return (0 <= x && x < rowSize && 0 <= y && y < colSize);
    }

    int dfs(const vector<vector<int>> &matrix, int x, int y, vector<vector<int>>& mem) {

        if(mem[x][y] != 0) return mem[x][y];

        int rowSize = matrix.size();
        int colSize = matrix[0].size();

        for(int k = 0; k < 4; ++k) {
            int nextX = x + m_xMoves[k];
            int nextY = y + m_yMoves[k];
            if(!isValidMove(nextX, nextY, rowSize, colSize)) continue;
            if(matrix[nextX][nextY] <= matrix[x][y]) continue;
            mem[x][y] = std::max(mem[x][y], dfs(matrix, nextX, nextY, mem));
        }
        mem[x][y] += 1;
        return mem[x][y];
    }
public:
    /**
     * @param matrix: an integer matrix
     * @return: the length of the longest increasing path
     */
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        int rowSize = matrix.size();
        if(rowSize == 0) return 0;
        int colSize = matrix[0].size();
        if(colSize == 0) return 0;

        vector<vector<int>> mem(rowSize, vector<int>(colSize, 0));
        int maxLen = 0;
        for(int i = 0; i < rowSize; ++i) {
            for(int j = 0; j < colSize; ++j) {
                maxLen = std::max(maxLen, dfs(matrix, i, j, mem));
            }
        }
        return maxLen;
    }
};