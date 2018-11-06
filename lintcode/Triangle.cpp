class Solution {
public:
    /**
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
    int minimumTotal(vector<vector<int>> &triangle) {
        int height = triangle.size();
        if(height == 0) return 0;

        vector<vector<int> > dp(height, vector<int>());
        for(int i = 0; i < height; ++i) {
            dp[i].resize(triangle[i].size());
        }
        dp[0][0] = triangle[0][0];

        for(int i = 1; i < height; ++i) {
            int rowLen = triangle[i].size();
            for(int j = 0; j < rowLen; ++j) {
                dp[i][j] = INT_MAX;
                for(int k = j; k > j - 2 && k > -1; --k) {
                    if(k >= dp[i-1].size()) continue;
                    dp[i][j] = std::min(dp[i][j], triangle[i][j] + dp[i-1][k]);
                }
            }
        }

        int minSum = INT_MAX;
        for(auto i : dp[height-1]) {
            minSum = std::min(minSum, i);
        }
        return minSum;
    }
};

// Space down to O(height)
class Solution {
public:
    /**
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
    int minimumTotal(vector<vector<int>> &triangle) {
        int height = triangle.size();
        if(height == 0) return 0;

        vector<int> dp(height); // actually means the length equals to the width of the last line
        dp[0] = triangle[0][0];

        for(int i = 1; i < height; ++i) {
            int rowLen = triangle[i].size();
            for(int j = rowLen - 1; j > -1; --j) {
                if(j == 0) {
                    dp[j] = dp[j] + triangle[i][j];
                } else if (j == rowLen - 1) {
                    dp[j] = dp[j-1] + triangle[i][j];
                } else {
                    dp[j] = std::min(dp[j-1], dp[j]) + triangle[i][j];
                }
            }
        }

        int minSum = INT_MAX;
        for(auto i : dp) {
            minSum = std::min(minSum, i);
        }
        return minSum;
    }
};