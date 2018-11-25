class Solution {
public:
    #define MOD 1000000007
    /**
     * @param N: a integer
     * @return: return a integer
     */
    int numTilings(int N) {
        if (N < 0) {
            return 0;
        }

        // empty, lower_empty, upper_empty
        vector<vector<long long>> dp(3, vector<long long>(3, 0));
        dp[0][0] = 1;
        dp[1][0] = 1;

        for (int i = 2; i <= N; ++i) {
            dp[i%3][0] = (dp[(i-1)%3][0] + dp[(i-2)%3][0] + dp[(i-1)%3][1] + dp[(i-1)%3][2])%MOD;
            dp[i%3][1] = (dp[(i-2)%3][0] + dp[(i-1)%3][2])%MOD;
            dp[i%3][2] = (dp[(i-2)%3][0] + dp[(i-1)%3][1])%MOD;
        }

        return dp[N%3][0];
    }
};