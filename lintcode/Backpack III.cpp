class Solution {
public:
    /**
     * @param A: an integer array
     * @param V: an integer array
     * @param m: An integer
     * @return: an array
     */
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        int len = A.size();
        if(len == 0) return 0;

        vector<vector<int> > dp(len + 1, vector<int>(m + 1, -1));
        dp[0][0] = 0;
        for(int i = 1; i <= len; ++i) {
            for(int j = 0; j <= m; ++j) {
                dp[i][j] = dp[i-1][j];
                if(j >= A[i-1] && dp[i][j - A[i-1]] != -1) {
                    dp[i][j] = std::max(dp[i][j], dp[i][j-A[i-1]] + V[i-1]);
                }

            }
        }

        int res = 0;
        for(int i = 0; i <= m; ++i) {
            if(dp[len][i] != -1) {
                res = std::max(res, dp[len][i]);
            }
        }

        return res;
    }
};

// With space improvement
class Solution {
public:
    /**
     * @param A: an integer array
     * @param V: an integer array
     * @param m: An integer
     * @return: an array
     */
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        int len = A.size();
        if(len == 0) return 0;

        vector<int> dp(m + 1, -1);
        dp[0] = 0;
        for(int i = 1; i <= len; ++i) {
            for(int j = A[i-1]; j <= m; ++j) {
                if(dp[j - A[i-1]] != -1) {
                    dp[j] = std::max(dp[j], dp[j-A[i-1]] + V[i-1]);
                }
            }
        }

        int res = 0;
        for(int i = 0; i <= m; ++i) {
            if(dp[i] != -1) {
                res = std::max(res, dp[i]);
            }
        }

        return res;
    }
};