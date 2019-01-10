class Solution {
public:
    /**
     * @param nums: the array
     * @return: the minimum times to flip digit
     */
    int flipDigit(vector<int> &nums) {
        int n = nums.size();
        if(n <= 1) return 0;

        // for previous i elements, ending with 0 or 1
        vector<vector<int>> dp(2, vector<int>(2, 0));

        for(int i = 1; i <= n; ++i) {
            if(nums[i-1] == 0) {
                dp[i%2][0] = std::min(dp[(i-1)%2][0], dp[(i-1)%2][1]);
                dp[i%2][1] = dp[(i-1)%2][1] + 1;
            } else {
                dp[i%2][0] = std::min(dp[(i-1)%2][0] + 1, dp[(i-1)%2][1] + 1);
                dp[i%2][1] = dp[(i-1)%2][1];
            }
        }

        return std::min(dp[n%2][0], dp[n%2][1]);
    }
};