class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        int len = prices.size();

        vector<vector<int> > dp(2, vector<int>(5, INT_MIN));

        dp[0][0] = 0;
        //for(int i = 1; i < 5; ++i) dp[0][i] = INT_MIN;

        for(int i = 1; i <= len; ++i) {
            for(int j = 0; j < 5; ++j) {
                if(j&1) { // odd index, even days 2, 4, with holdings
                    dp[i%2][j] = dp[(i-1)%2][j-1];
                    if(i-2 >= 0 && dp[(i-1)%2][j] != INT_MIN) dp[i%2][j] = std::max(dp[(i-1)%2][j] + prices[i-1] - prices[i-2], dp[i%2][j]);
                } else { // even index, odd days 1, 3, 5 no holdings
                    dp[i%2][j] = dp[(i-1)%2][j];
                    if(i-2 >= 0 && j > 0 && dp[(i-1)%2][j-1] != INT_MIN) dp[i%2][j] = std::max(dp[i%2][j], dp[(i-1)%2][j-1] + prices[i-1] - prices[i-2]);
                }
            }
        }

        int maxP = INT_MIN;
        for(int i = 0; i < 5;) {
            maxP = std::max(maxP, dp[len%2][i]);
            i += 2;
        }
        return maxP;
    }
};