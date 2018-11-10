class Solution {
private:
    int m_rowMoves[4] = {-1, 0, 1, 0};
    int m_colMoves[4] = {0, 1, 0, -1};

    bool isValidMove(int rowSize, int colSize, int r, int c) {
        return (0 <= r && r < rowSize && 0 <= c && c < colSize);
    }

    int memoSearch(const vector<vector<int> > &A, int r, int c, vector<vector<int> >& dp, vector<vector<bool> >& visited) {
        if(visited[r][c]) return dp[r][c];

        int longest = 1;
        int rowSize = A.size();
        int colSize = A[0].size();
        for(int i = 0; i < 4; ++i) {
            int nextRow = r + m_rowMoves[i];
            int nextCol = c + m_colMoves[i];
            if(!isValidMove(rowSize, colSize, nextRow, nextCol)) continue;
            if(A[nextRow][nextCol] > A[r][c]) longest = std::max(longest, 1 + memoSearch(A, nextRow, nextCol, dp, visited));
        }

        visited[r][c] = true;
        dp[r][c] = longest;
        return longest;
    }
public:
    /**
     * @param A: An integer matrix
     * @return: an integer
     */
    int longestContinuousIncreasingSubsequence2(vector<vector<int>> &A) {
        int rowSize = A.size();
        if(rowSize == 0) return 0;
        int colSize = A[0].size();
        if(colSize == 0) return 0;

        int longest = 0;
        vector<vector<int> > dp(rowSize, vector<int>(colSize, 0));
        vector<vector<bool> > visited(rowSize, vector<bool>(colSize, false));

        for(int i = 0; i < rowSize; ++i) {
            for(int j = 0; j < colSize; ++j) {
                dp[i][j] = memoSearch(A, i, j, dp, visited);
                longest = std::max(longest, dp[i][j]);
            }
        }
        return longest;
    }
};