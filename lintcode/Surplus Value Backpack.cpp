class Solution {
public:
    /**
     * @param k1: The coefficient of A
     * @param k2: The  coefficient of B
     * @param c: The volume of backpack
     * @param n: The amount of A
     * @param m: The amount of B
     * @param a: The volume of A
     * @param b: The volume of B
     * @return: Return the max value you can get
     */
    long long getMaxValue(int k1, int k2, int c, int n, int m, vector<int> &a, vector<int> &b) {

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        vector<long long> aSum(n+1, 0);
        vector<long long> bSum(m+1, 0);
        for(int i = 1; i <= n; ++i) {
            aSum[i] = aSum[i-1] + a[i-1];
        }

        for(int i = 1; i <= m; ++i) {
            bSum[i] = bSum[i-1] + b[i-1];
        }

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));
        long long res = 0;

        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j <=m; ++j) {
                if(i == 0 && j == 0) {
                    dp[i][j] = 0;
                    continue;
                }

                long long total = aSum[i] + bSum[j];
                dp[i][j] = 0;
                if(total > c) {
                    continue;
                }

                if(i > 0) {
                    // last item is a[i-1]
                    dp[i][j] = std::max(dp[i][j], dp[i-1][j] + k1 * (c - total));
                }

                if(j > 0) {
                    // last item is a[i-1]
                    dp[i][j] = std::max(dp[i][j], dp[i][j-1] + k2 * (c - total));
                }

                res = std::max(res, dp[i][j]);
            }
        }

        return res;

    }
};