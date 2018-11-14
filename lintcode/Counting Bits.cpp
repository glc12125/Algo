class Solution {
public:
    /**
     * @param num: a non negative integer number
     * @return: an array represent the number of 1's in their binary
     */
    vector<int> countBits(int num) {
        int len = num + 1;
        vector<int> dp(len, 0);

        for(int i = 1; i <= num; ++i) {
            dp[i] = dp[i>>1] + i % 2;
        }

        return dp;
    }
};