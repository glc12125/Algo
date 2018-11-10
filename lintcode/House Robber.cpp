class Solution {
public:
    /**
     * @param A: An array of non-negative integers
     * @return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> &A) {
        int len = A.size();

        vector<long long> dp(2);
        dp[0] = 0;
        dp[1] = A[0];

        for(int i = 2; i <= len; ++i) {
            dp[i%2] = std::max(dp[(i - 1)%2], dp[(i-2)%2] + A[i-1]);
        }

        return dp[len%2];
    }
};