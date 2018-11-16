class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        int len = A.size();

        vector<vector<int> > dp(len + 1, vector<int>(m + 1, 0));

        for(int i = 1; i <= len; ++i) {
            for(int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i-1][j];
                if(j >= A[i-1]) dp[i][j] = std::max(dp[i][j], dp[i-1][j-A[i-1]] + V[i-1]);
            }
        }

        return dp[len][m];
    }
};

// With printing of the path
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        int len = A.size();
        if(len == 0) return 0;

        vector<vector<int> > dp(len + 1, vector<int>(m + 1, -1));
        vector<vector<int>> pi(len + 1, vector<int>(m + 1, -1));
        dp[0][0] = 0;
        for(int i = 1; i <= len; ++i) {
            for(int j = 0; j <= m; ++j) {
                dp[i][j] = dp[i-1][j];
                pi[i][j] = 0;
                if(j >= A[i-1] && dp[i-1][j - A[i-1]] != -1) {
                    dp[i][j] = std::max(dp[i][j], dp[i-1][j-A[i-1]] + V[i-1]);
                    if(dp[i][j] == dp[i-1][j-A[i-1]] + V[i-1]) {
                        pi[i][j] = 1;
                    }
                }

            }
        }

        int res = 0;
        int j = -1;
        for(int i = 0; i <= m; ++i) {
            if(dp[len][i] != -1) {
                res = std::max(res, dp[len][i]);
                if(res == dp[len][i]) {
                    j = i;
                }
            }
        }

        vector<bool> selected(len, false);
        for(int i = len; i >= 1; --i) {
            if(pi[i][j] == 1) {
                selected[i - 1] = true;
                j -= A[i-1];
            }
        }

        for(int i = 0; i < len; ++i) {
            if(selected[i]) {
                std::cout << "Item " << i << ", weight: " << A[i] << ", value: " << V[i] << "\n";
            }
        }

        return res;
    }
};