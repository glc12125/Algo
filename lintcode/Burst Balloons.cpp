class Solution {
private:
    long long memoBurst(const vector<int> &nums, int start, int end, vector<vector<long long>>& dp, vector<vector<bool>>& visited) {
        if(visited[start][end]) return dp[start][end];
        visited[start][end] = true;

        for(int k = start; k <= end; ++k) {
            long long score = nums[start - 1] * nums[k] * nums[end+1];
            dp[start][end] = std::max(dp[start][end], memoBurst(nums, start, k - 1, dp, visited) + memoBurst(nums, k + 1, end, dp, visited) + score);
        }

        return dp[start][end];
     }
public:
    /**
     * @param nums: A list of integer
     * @return: An integer, maximum coins
     */
    int maxCoins(vector<int> &nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];

        vector<vector<long long> > dp(len + 2, vector<long long>(len + 2));
        vector<vector<bool> > visited(len + 2, vector<bool>(len + 2));

        vector<int> expandedNums(len + 2, 1);
        for(int i = 1; i <= len; ++i) {
            expandedNums[i] = nums[i - 1];
        }

        return memoBurst(expandedNums, 1, len, dp, visited);
    }
};


// DP, time O(N^3), Space O(N^2)
int maxCoins(vector<int> &nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> paddedNums(n + 2, 1);
        for(int i = 1; i <= n; ++i) {
            paddedNums[i] = nums[i - 1];
        }
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for(int i = 0; i <= n; ++i) {
            dp[i][i+1] = 0;
        }

        for(int len = 1; len <= n; ++len) {
            // i [0, ... , n - len]
            for(int i = 0; i <= n - len; ++i) {
                int j = i + len + 1;
                dp[i][j] = 0;
                for(int k = i + 1; k < j; ++k) {
                    dp[i][j] = std::max(dp[i][j], dp[i][k] + dp[k][j] + paddedNums[i] * paddedNums[k] * paddedNums[j]);
                }
            }
        }

        /*for(int i = 0; i <= n + 1; ++i) {
            std::cout << "\n";
            for(int j = 0; j <= n + 1; ++j) {
                std::cout << dp[i][j] << " ";
            }
        }*/

        return dp[0][n+1];
    }