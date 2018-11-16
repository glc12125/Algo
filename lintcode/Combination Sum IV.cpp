class Solution {
private:
    int dfs(const vector<int>& nums, int target, unordered_map<int, int>& mem) {
        if(mem.count(target)) {
            return mem[target];
        }

        if(target == 0) {
            mem[0] = 1;
            return 1;
        }

        int sum = 0;
        if(target < 0) return sum;

        for(int i = 0; i < nums.size(); ++i) {
            sum += dfs(nums, target - nums[i], mem);
        }

        mem[target] = sum;
        return sum;
    }
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
     int backPackVI(vector<int> &nums, int target) {
        unordered_map<int, int> mem;
        return dfs(nums, target, mem);
     }

    int backPackVIDp(vector<int> &nums, int target) {
        int len = nums.size();
        if(len == 0) return 0;

        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for(int j = 1; j <= target; ++j) {
            for(int i = 1; i <= len; ++i) {
                if(j >= nums[i-1]) {
                    dp[j] += dp[j-nums[i-1]];
                }
            }
        }

        for(auto i : dp) std::cout << i << " ";

        return dp[target];
    }
}