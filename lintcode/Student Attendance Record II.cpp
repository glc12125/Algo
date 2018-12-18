class Solution {
public:
    /**
     * @param n: an integer
     * @return: return an integer
     */
    int checkRecord(int n) {
        int M = 1e9 + 7;
        // for i numbers, the number of combinations with maximum j 'A' and
        // maximum k continuous 'L'
        int dp[n + 1][2][3] = {0};
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                dp[0][j][k] = 1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 3; ++k) {
                    int val = dp[i - 1][j][2];
                    if (j > 0) val = (val + dp[i - 1][j - 1][2]) % M;
                    if (k > 0) val = (val + dp[i - 1][j][k - 1]) % M;
                    dp[i][j][k] = val;
                }
            }
        }
        return dp[n][1][2];
    }
};