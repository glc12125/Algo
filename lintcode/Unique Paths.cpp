class Solution {
public:
    /**
     * @param m: positive integer (1 <= m <= 100)
     * @param n: positive integer (1 <= n <= 100)
     * @return: An integer
     */
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0) return 0;

        vector<vector<int>> dp(2, vector<int>(n));
        dp[0][0] = 1;
        int prev = 0;
        int curr = 0;
        for(int i = 0; i < m; ++i) {
            prev = curr;
            curr = 1 - curr;
            for(int j = 0; j < n; ++j) {
                if(i == 0 || j == 0) {dp[curr][j] = 1;}
                else {
                    dp[curr][j] = dp[prev][j] + dp[curr][j-1];
                }
            }
        }

        return dp[curr][n-1];
    }
};