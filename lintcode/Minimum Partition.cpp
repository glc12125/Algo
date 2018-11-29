class Solution {
public:
    /**
     * @param nums: the given array
     * @return: the minimum difference between their sums
     */
    int findMin(vector<int> &nums) {
        int len = nums.size();
        if(len == 0) return 0;

        long long sum = accumulate(nums.begin(), nums.end(), 0);

        long long capacity = (sum >> 1);
        vector<bool> dp(capacity + 1, false);
        dp[0] = true;
        for(int i = 1; i <= len; ++i) {
            for(int j = capacity; j >= nums[i-1]; --j) {
                dp[j] = dp[j] || dp[j-nums[i-1]];
            }
        }

        long long maxSumHalf = -1;
        for(int j = capacity; j >= 0; --j) {
            if(dp[j]) {
                maxSumHalf = j;
                break;
            }
        }
        return sum - maxSumHalf - maxSumHalf;
    }
};