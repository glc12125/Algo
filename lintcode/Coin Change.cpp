class Solution {
public:
    /**
     * @param coins: a list of integer
     * @param amount: a total amount of money amount
     * @return: the fewest number of coins that you need to make up
     */
    int coinChange(vector<int> &coins, int amount) {
        int len = coins.size();
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i) {
            dp[i] = INT_MAX;
            for(int j = 0; j < len; ++j) {
                if(i >= coins[j] && dp[i - coins[j]] != INT_MAX) {
                    dp[i] = std::min(dp[i], dp[i-coins[j]] + 1);
                }
            }
        }

        if(dp[amount] == INT_MAX) {
            return -1;
        } else {
            return dp[amount];
        }
    }
};