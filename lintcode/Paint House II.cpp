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
        vector<vector<int>> pi(houseNum + 1, vector<int>(colorNum));

        for(int i = 1; i <= houseNum; ++i) {
            int minIndex = -1;
            int secondMinIndex = -1;

            for(int j = 0; j < colorNum; ++j) {
                if(minIndex == -1 || dp[(i-1)%2][j] < dp[(i-1)%2][minIndex]) {
                    secondMinIndex = minIndex;
                    minIndex = j;
                } else {
                    if(secondMinIndex == -1 || dp[(i-1)%2][j] < dp[(i-1)%2][secondMinIndex])
                    secondMinIndex = j;
                }
            }

            for(int j = 0; j < colorNum; ++j) {
                if(j != minIndex) {
                    dp[i%2][j] = dp[(i-1)%2][minIndex] + costs[i-1][j];
                    pi[i][j] = minIndex;
                } else {
                    dp[i%2][j] = dp[(i-1)%2][secondMinIndex] + costs[i-1][j];
                    pi[i][j] = secondMinIndex;
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
        int k = -1;
        for(int i = 0; i < colorNum; ++i) {
            minimum = std::min(minimum, dp[houseNum%2][i]);
            if(minimum == dp[houseNum%2][i]) {
                k = i;
            }
        }

        vector<int> color(houseNum);
        for(int i = houseNum; i > 0; --i) {
            color[i-1] = k;
            k = pi[i][k];
        }

        for(int i = 0; i < houseNum; ++i) {
            std::cout << "House: " << i << ", color: " << color[i] << "\n";
        }
        return minimum;
    }
};