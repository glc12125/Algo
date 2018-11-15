class Solution {
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &costs) {
        int houseNum = costs.size();
        if(houseNum == 0) return 0;
        int colorNum = costs[0].size();
        if(colorNum == 0) return 0;

        vector<vector<int>> dp(2, vector<int>(colorNum, 0));

        for(int i = 1; i <= houseNum; ++i) {
            int minVal = dp[(i-1)%2][0];
            int minIndex = 0;
            int secondMinVal = dp[(i-1)%2][0];
            int secondMinIndex = 0;
            for(int j = 0; j < colorNum; ++j) {
                if(dp[(i-1)%2][j] < minVal) {
                    secondMinVal = minVal;
                    secondMinIndex = minIndex;
                    minVal = dp[(i-1)%2][j];
                    minIndex = j;
                }
            }

            for(int j = 0; j < colorNum; ++j) {
                if(j != minIndex) {
                    dp[i%2][j] = minVal + costs[i-1][j];
                } else {
                    dp[i%2][j] = secondMinVal + costs[i-1][j];
                }
            }/*
            for(int j = 0; j < colorNum; ++j) {
                dp[i%2][j] = INT_MAX;
                for(int k = 0; k < colorNum; ++k) {
                    if(k != j) {
                        dp[i%2][j] = std::min(dp[i%2][j], dp[(i-1)%2][k] + costs[i-1][j]);
                    }
                }
            }*/
        }

        int minimum = INT_MAX;
        for(int i = 0; i < colorNum; ++i) {
            minimum = std::min(minimum, dp[houseNum%2][i]);
        }
        return minimum;
    }
};