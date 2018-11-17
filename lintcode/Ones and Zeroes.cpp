class Solution {
public:
    /**
     * @param strs: an array with strings include only 0 and 1
     * @param m: An integer
     * @param n: An integer
     * @return: find the maximum number of strings
     */
    int findMaxForm(vector<string> &A, int m, int n) {
        int len = A.size();
        if(len == 0) return 0;

        int T = A.size();

        vector<int> cnt0(T);
        vector<int> cnt1(T);

        for(int i = 0; i < T; ++i) {
            cnt0[i] = 0;
            cnt1[i] = 0;
            for(auto c : A[i]) {
                if(c == '0') cnt0[i]++;
                else cnt1[i]++;
            }
        }

        vector<vector<vector<int>>> dp (2, vector<vector<int>>(m + 1, vector<int>(n+1)));

        for(int i = 0; i <= T; ++i) {
            for(int j = 0; j <= m; ++j) {
                for(int k = 0; k <=n; ++k) {
                    if(i==0) {
                        dp[i%2][j][k] = 0;
                        continue;
                    }

                    dp[i%2][j][k] = dp[(i-1)%2][j][k];
                    if(j >= cnt0[i-1] && k >= cnt1[i-1]) {
                        dp[i%2][j][k] = std::max(dp[i%2][j][k], dp[(i-1)%2][j-cnt0[i-1]][k-cnt1[i-1]] + 1);
                    }
                }
            }
        }

        return dp[T%2][m][n];
    }
};