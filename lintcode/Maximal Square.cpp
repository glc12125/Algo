class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int>> &matrix) {
        int rowSize = matrix.size();
        if(rowSize == 0) return 0;
        int colSize = matrix[0].size();
        if(colSize == 0) return 0;

        vector<vector<int>> dp(rowSize, vector<int>(colSize, 0));

        int maxLen = 0;
        for(int j = 0; j < colSize; ++j) {
            dp[0][j] = matrix[0][j];
            maxLen = std::max(maxLen, dp[0][j]);
        }

        for(int i = 0; i < rowSize; ++i) {
            dp[i][0] = matrix[i][0];
             maxLen = std::max(maxLen, dp[i][0]);
        }


        for(int i = 1; i < rowSize; ++i) {
            for(int j = 1; j < colSize; ++j) {
                if(matrix[i][j] == 1) {
                    if(dp[i][j-1] > 0 && dp[i-1][j] > 0 && dp[i-1][j-1] > 0) {
                        dp[i][j] = std::min(std::min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
                    } else dp[i][j] = 1;
                    maxLen = std::max(maxLen, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return maxLen * maxLen;
    }
};

// With rolling array, that will use O(N), where N is the column size
class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int>> &matrix) {
        int rowSize = matrix.size();
        if(rowSize == 0) return 0;
        int colSize = matrix[0].size();
        if(colSize == 0) return 0;

        vector<vector<int>> dp(2, vector<int>(colSize, 0));

        int maxLen = 0;
        int curr = 0;
        int prev = 1;
        for(int j = 0; j < colSize; ++j) {
            dp[curr][j] = matrix[0][j];
            maxLen = std::max(maxLen, dp[curr][j]);
        }

        for(int i = 1; i < rowSize; ++i) {
            prev = curr;
            curr = 1 - curr;
            dp[curr][0] = matrix[i][0];
            maxLen = std::max(maxLen, dp[curr][0]);
            for(int j = 1; j < colSize; ++j) {
                if(matrix[i][j] == 1) {
                    if(dp[curr][j-1] > 0 && dp[prev][j] > 0 && dp[prev][j-1] > 0) {
                        dp[curr][j] = std::min(std::min(dp[curr][j-1], dp[prev][j]), dp[prev][j-1]) + 1;
                    } else dp[curr][j] = 1;
                    maxLen = std::max(maxLen, dp[curr][j]);
                } else {
                    dp[curr][j] = 0;
                }
            }
        }

        return maxLen * maxLen;
    }
};