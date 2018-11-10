class Solution {
private:
    long long houseRobber1(const vector<int> &nums, int start, int end) {
        if(start == end) return nums[start];
        if(start + 1 == end) return std::max(nums[start], nums[end]);

        vector<long long> dp(2);
        dp[start%2] = nums[start];
        dp[(start + 1) % 2] = std::max(nums[start], nums[start + 1]);

        for(int i = start + 2; i <= end; ++i) {
            dp[i%2] = std::max(dp[(i - 1)%2], dp[(i-2)%2] + nums[i]);
        }

        return dp[end%2];
    }
public:
    /**
     * @param nums: An array of non-negative integers.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int> &nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];

        long long first = houseRobber1(nums, 0, len - 2);
        long long second = houseRobber1(nums, 1, len - 1);
        return std::max(first, second);

    }
};