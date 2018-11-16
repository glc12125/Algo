class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers
     * @param target: An integer
     * @return: An integer
     */
    int backPackV(vector<int> &nums, int target) {
        int len = nums.size();
        if(len == 0) return 0;

        vector<vector<int>> dp(len + 1, vector<int>(target + 1, 0));

        dp[0][0] = 1;

        for(int i = 1; i <= len; ++i) {
            dp[i][0] = 1;
            for(int j = 1; j <= target; ++j) {
                dp[i][j] = dp[i-1][j];
                if(j >= nums[i-1]) dp[i][j] += dp[i-1][j - nums[i-1]];
            }
        }

        return dp[len][target];
    }
};

// Time O(target*N), space O(target)
class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers
     * @param target: An integer
     * @return: An integer
     */
    int backPackV(vector<int> &nums, int target) {
        int len = nums.size();
        if(len == 0) return 0;

        vector<int> dp(target + 1, 0);

        dp[0] = 1;

        for(int i = 1; i <= len; ++i) {
            for(int j = target; j >= nums[i-1]; --j) {
                dp[j] += dp[j-nums[i-1]];
            }
        }

        return dp[target];
    }
};