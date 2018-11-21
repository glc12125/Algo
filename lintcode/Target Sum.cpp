// DFS, time O(2^N)
class Solution {
private:
    void dfs(const vector<int>& nums, int index, int curr, int s, int& cnt) {
        int len = nums.size();
        if(index == len) {
            if(curr == s) ++cnt;
            return;
        }

        dfs(nums, index + 1, curr - nums[index], s, cnt);
        dfs(nums, index + 1, curr + nums[index], s, cnt);
    }
public:
    /**
     * @param nums: the given array
     * @param s: the given target
     * @return: the number of ways to assign symbols to make sum of integers equal to target S
     */
    int findTargetSumWays(vector<int> &nums, int s) {
        int cnt = 0;
        dfs(nums, 0, 0, s, cnt);
        return cnt;
    }
};

// DP, time O(N * SUM), space O(Sum)
class Solution {
public:
    /**
     * @param nums: the given array
     * @param s: the given target
     * @return: the number of ways to assign symbols to make sum of integers equal to target S
     */
    int findTargetSumWays(vector<int> &nums, int s) {

        int len = nums.size();
        if(len == 0 && s != 0) return 0;
        if(len == 0 && s == 0) return 1;

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < std::abs(s)) {
            return 0;
        }

        int sumDouble = sum + sum;
        vector<vector<int>> dp(2, vector<int>(sumDouble + 1, 0));

        if(nums[0] == 0) {
            dp[0][sum] = 2;
        } else {
            dp[0][sum+nums[0]] = 1;
            dp[0][sum-nums[0]] = 1;
        }

        for(int i = 1; i < len; ++i) {
            for(int j = 0; j <= sumDouble; ++j) {
                dp[i%2][j] = 0;
                if(j >= nums[i]) dp[i%2][j] += dp[(i-1)%2][j-nums[i]];
                if(j+nums[i] <= sumDouble) dp[i%2][j] += dp[(i-1)%2][j+nums[i]];
            }
        }

        return dp[(len-1)%2][s + sum];
    }
};