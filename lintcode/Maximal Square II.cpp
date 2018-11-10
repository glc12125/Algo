// DP, basic implementation with O(M*N) space
class Solution {
public:
    /**
     * @param matrix: a matrix of 0 an 1
     * @return: an integer
     */
    int maxSquare2(vector<vector<int>> &matrix) {
        int rowSize = matrix.size();
        if(rowSize == 0) return 0;
        int colSize = matrix[0].size();
        if(colSize == 0) return 0;

        vector<vector<int>> dp(2, vector<int>(colSize, 0));
        vector<vector<int>> up(rowSize, vector<int>(colSize, 0));
        vector<vector<int>> left(rowSize, vector<int>(colSize, 0));

        int maxLen = 0;
        int prev = 0;
        int curr = 0;
        for(int j = 0; j < colSize; ++j) {
            dp[curr][j] = matrix[0][j];
            up[0][j] = 1 - matrix[0][j];
            maxLen = std::max(maxLen, dp[curr][j]);
        }

        for(int i = 1; i < rowSize; ++i) {
            prev = curr;
            curr = 1 - curr;
            dp[curr][0] = matrix[i][0];
            left[i][0] = 1 - matrix[i][0];
            maxLen = std::max(maxLen, dp[curr][0]);
            for(int j = 1; j < colSize; ++j) {
                if(matrix[i][j] == 1) {
                    left[i][j] = 0;
                    up[i][j] = 0;
                    if(dp[prev][j-1] > 0) {
                        dp[curr][j] = std::min(std::min(left[i][j-1], up[i-1][j]), dp[prev][j-1]) + 1;
                    } else dp[curr][j] = 1;
                    maxLen = std::max(maxLen, dp[curr][j]);
                } else {
                    left[i][j] = 1;
                    up[i][j] = 1;
                    dp[curr][j] = 0;
                    up[i][j] = up[i - 1][j] + 1;
                    left[i][j] = left[i][j - 1] + 1;
                }
            }
        }

        return maxLen * maxLen;
    }
};

// DP, rolling array implementation with O(M + N) space
class Solution {
public:
    /**
     * @param matrix: a matrix of 0 an 1
     * @return: an integer
     */
    int maxSquare2(vector<vector<int>> &matrix) {
        int rowSize = matrix.size();
        if(rowSize == 0) return 0;
        int colSize = matrix[0].size();
        if(colSize == 0) return 0;

        vector<vector<int>> dp(2, vector<int>(colSize, 0));
        vector<vector<int>> up(2, vector<int>(colSize, 0));
        vector<vector<int>> left(rowSize, vector<int>(2, 0));

        int maxLen = 0;
        int prev = 0;
        int curr = 0;
        for(int j = 0; j < colSize; ++j) {
            dp[curr][j] = matrix[0][j];
            up[curr][j] = 1 - matrix[0][j];
            maxLen = std::max(maxLen, dp[curr][j]);
        }

        for(int i = 1; i < rowSize; ++i) {
            prev = curr;
            curr = 1 - curr;
            dp[curr][0] = matrix[i][0];
            left[i][0] = 1 - matrix[i][0];
            maxLen = std::max(maxLen, dp[curr][0]);
            for(int j = 1; j < colSize; ++j) {
                if(matrix[i][j] == 1) {
                    left[i][j%2] = 0;
                    up[curr][j] = 0;
                    if(dp[prev][j-1] > 0) {
                        dp[curr][j] = std::min(std::min(left[i][(j-1) % 2], up[prev][j]), dp[prev][j-1]) + 1;
                    } else dp[curr][j] = 1;
                    maxLen = std::max(maxLen, dp[curr][j]);
                } else {
                    left[i][j%2] = 1;
                    up[curr][j] = 1;
                    dp[curr][j] = 0;
                    up[curr][j] = up[prev][j] + 1;
                    left[i][j%2] = left[i][(j - 1)%2] + 1;
                }
            }
        }

        return maxLen * maxLen;
    }
};