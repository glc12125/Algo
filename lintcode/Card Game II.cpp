class Solution {
public:
    /**
     * @param cost: costs of all cards
     * @param damage: damage of all cards
     * @param totalMoney: total of money
     * @param totalDamage: the damage you need to inflict
     * @return: Determine if you can win the game
     */
    bool cardGame(vector<int> &cost, vector<int> &damage, int totalMoney, int totalDamage) {
        int len = cost.size();
        if(len == 0) return false;

        vector<vector<int>> dp(len + 1, vector<int>(totalMoney + 1, 0));

        for(int i = 1; i <= len; ++i) {
            for(int j = 1; j <= totalMoney; ++j) {
                dp[i][j] = dp[i-1][j];
                if(j >= cost[i-1]) {
                    dp[i][j] = std::max(dp[i][j], damage[i-1] + dp[i-1][j-cost[i-1]]);
                }
                if(dp[i][j] >= totalDamage) return true;
            }
        }

        return false;
    }
};