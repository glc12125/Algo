class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        if(n == 0) return 0;

        vector<vector<int>> f(2, vector<int>(3));
        f[0][0] = 0;
        f[0][1] = 0;
        f[0][2] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < 3; ++j) {
                f[i%2][j] = INT_MAX;
                for (int k = 0; k < 3; ++k) {
                    if(k != j && f[(i-1)%2][k] + costs[i - 1][j] < f[i%2][j]) {
                        f[i%2][j] = f[(i-1)%2][k] + costs[i - 1][j];
                    }
                }
            }
        }

        int result = f[n%2][0];
        for(int i = 1; i < 3; ++i) {
            result = std::min(result, f[n%2][i]);
        }
        return result;
    }
};

// Optimized
class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        if(n == 0) return 0;
        int m = costs[0].size();
        if(m == 0) return 0;

        vector<vector<int>> dp(2, vector<int>(m));
        for(int i = 0; i < m; ++i) {
            dp[0][i] = 0;
        }

        for(int i = 1; i <= n; ++i) {
            int minimum = INT_MAX;
            int secondMin = INT_MAX;
            for(int j = 0; j < m; ++j) {
                if(minimum > dp[(i-1)%2][j]) {
                    secondMin = minimum;
                    minimum = dp[(i-1)%2][j];
                } else {
                    secondMin = std::min(secondMin, dp[(i-1)%2][j]);
                }
            }

            for(int j = 0; j < m; ++j) {
                if(dp[(i-1)%2][j] == minimum) {
                    dp[i%2][j] = secondMin + costs[i-1][j];
                } else {
                    dp[i%2][j] = minimum + costs[i-1][j];
                }
            }
        }

        int result = INT_MAX;
        for(int i = 0; i < m; ++i) {
            result = std::min(dp[n%2][i], result);
        }
        return result;
    }
};