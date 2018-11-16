class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackIV(vector<int> &nums, int target) {
        int len = nums.size();
        if(len == 0) return 0;

        vector<int> dp(target + 1, 0);
        dp[0] = 1;


        for(int i = 0; i < len; ++i) {
            for(int j = nums[i]; j <= target; ++j) {
                dp[j] += dp[j-nums[i]];
            }
        }

        //for(auto i : dp) std::cout << i << " ";

        return dp[target];
    }
};