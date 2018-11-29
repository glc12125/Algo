class Solution {
public:
    /**
     * @param height: the given height
     * @param width: the given width
     * @return: the number of paths you can reach the end
     */
    int uniquePath(int height, int width) {
        if(height == 0 || width == 0) return 0;


        vector<vector<long long>> dp(height, vector<long long>(width, 0));

        dp[0][0] = 1;
        for(int j = 1; j < width; ++j) {
            for(int i = height - 1; i >= 0; --i) {
                if(i == height - 1)  {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = (dp[i+1][j-1] + dp[i][j-1]) % 1000000007;
                if(i > 0) {
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }

        return dp[0][width-1];
    }
};