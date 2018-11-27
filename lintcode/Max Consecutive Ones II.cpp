class Solution {
public:
    /**
     * @param nums: a list of integer
     * @return: return a integer, denote  the maximum number of consecutive 1s
     */
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int len = nums.size();
        if(len == 0) return 0;

        int maxLen = 0;
        int prevZeroPos = 0;
        int start = 0;
        bool metZero = false;
        for(int i = 0; i < len; ++i) {
            if(nums[i] == 0){
                if(metZero){
                    start = prevZeroPos + 1;
                } else {
                    metZero = true;
                }
                prevZeroPos = i;
            }
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};

// DP, time O(N)
class Solution {
public:
    /**
     * @param nums: a list of integer
     * @return: return a integer, denote  the maximum number of consecutive 1s
     */
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int n = nums.size();
        // 0 means do not flip, 1 means with one flip
        vector<vector<int>> dp(2, vector<int>(2, 0));

        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if(nums[i-1] == 0) {
                dp[i%2][0] = 0;
                dp[i%2][1] = dp[(i-1)%2][0] + 1;
            } else {
                dp[i%2][0] = dp[(i-1)%2][0] + 1;
                dp[i%2][1] = dp[(i-1)%2][1] + 1;
            }
            res = std::max(res, dp[i%2][1]);
        }
        return res;
    }
};