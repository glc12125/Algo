class Solution {
public:
    /**
     * @param n: a positive integer
     * @return: An integer
     */
    int numSquares(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for(int i = 2; i <=n; ++i) {
            dp[i] = INT_MAX;
            int maxFactor = std::sqrt(i);
            for(int j = maxFactor; j > 0; --j) {
                int square = j * j;
                if(square > i) continue;
                dp[i] = std::min(dp[i], dp[i-square] + 1);
            }
        }

        return dp[n] == INT_MAX ? 0 : dp[n];
    }
};