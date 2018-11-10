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