// Time O(N*N*M) -> O(N*M), space O(M*N)
class Solution {
public:
    /**
     * @param n: the max identifier of planet.
     * @param m: gold coins that Sven has.
     * @param limit: the max difference.
     * @param cost: the number of gold coins that reaching the planet j through the portal costs.
     * @return: return the number of ways he can reach the planet n through the portal.
     */
    long long getNumberOfWays(int n, int m, int limit, vector<int> &cost) {
        vector<vector<long>> dp(n+1, vector<long>(m+1));
        vector<vector<long>> sum(n+1, vector<long>(m+1));
        for(int i = 0; i < m; ++i) {
            dp[0][i] = 0;
            sum[0][i] = 0;
        }

        dp[0][m] = 1;
        sum[0][m] = 1;

        for(int i = 1; i <=n; ++i) {
            for(int j = 0; j <= m; ++j) {
                dp[i][j] = 0;
                sum[i][j] = sum[i-1][j];
                if(j + cost[i] > m) continue;
                // use prefix sum to eliminate this loop
                /*for(int k = i - limit; k < i; ++k) {
                    if(k >= 0 && j + cost[i] <= m) {
                        dp[i][j] += dp[k][j + cost[i]];
                    }
                }*/
                dp[i][j] = sum[i-1][j+cost[i]];
                if(i - limit - 1 >= 0) {
                    dp[i][j] -= sum[i-1 - limit][j+cost[i]];
                }
                sum[i][j] += dp[i][j];
            }
        }

        long res = 0;
        for(int i =0; i <=m ;++i) {
            res += dp[n][i];
        }

        return res;
    }
};