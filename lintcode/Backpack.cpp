class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        int len = A.size();

        vector<vector<bool> > dp(2, vector<bool>(m + 1, false));
        dp[0][0] = true;

        for(int i = 1; i <= len; ++i) {
            for(int j = 0; j <= m; ++j) {
                dp[i%2][j] = dp[(i-1)%2][j];
                if(j >= A[i-1] && dp[(i-1)%2][j - A[i-1]]) dp[i%2][j] = true;
            }
        }

        for(int i = m; i >= 0; --i) {
            if(dp[len%2][i]) return i;
        }
        return 0;
    }
};