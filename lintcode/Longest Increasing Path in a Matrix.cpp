class Solution {
private:
    int m_xMoves[4] = {-1, 0, 1, 0};
    int m_yMoves[4] = {0, 1, 0, -1};
    int m_maxLen = 1;

    bool isValidMove(int x, int y, int rowSize, int colSize) {
        return (0 <= x && x < rowSize && 0 <= y && y < colSize);
    }

    int getKey(int x, int y, int colSize) {
        return x * colSize + y;
    }

    void dfs(const vector<vector<int>> &matrix, int x, int y, int currLen, unordered_set<int>& visited) {

        m_maxLen = std::max(m_maxLen, currLen);

        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        int currKey = getKey(x, y, colSize);

        for(int k = 0; k < 4; ++k) {
            int nextX = x + m_xMoves[k];
            int nextY = y + m_yMoves[k];
            if(!isValidMove(nextX, nextY, rowSize, colSize)) continue;
            int key = getKey(nextX, nextY, colSize);
            if(visited.count(key)) continue;
            if(matrix[nextX][nextY] <= matrix[x][y]) continue;
            dfs(matrix, nextX, nextY, currLen + 1, visited);
        }
        visited.erase(currKey);
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

        unordered_set<int> visited;
        for(int i = 0; i < rowSize; ++i) {
            for(int j = 0; j < colSize; ++j) {
                dfs(matrix, i, j, 1, visited);
            }
        }
        return m_maxLen;
    }
};