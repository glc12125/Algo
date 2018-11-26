class Solution {
public:
    /**
     * @param prices: a list of integers
     * @return: return a integer
     */
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        vector<int> buy(len);
        vector<int> sell(len);
        buy[0] = -prices[0];
        for(int i = 1; i < len; i++) {
            buy[i] = std::max(buy[i-1], (i > 1 ? sell[i-2] : 0) - prices[i]);
            sell[i] = std::max(sell[i-1], buy[i-1] + prices[i]);
        }
        return sell[len - 1];
    }
};