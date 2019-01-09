class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A) {
        int len = A.size();
        if(len == 0) return false;

        vector<bool> dp(len);

        dp[0] = true;

        for(int i = 1; i < len; ++i) {
            dp[i] = false;
            for(int j = 0; j < i; ++j) {
                if(dp[j] && A[j] >= i - j) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[len - 1];
    }
};
