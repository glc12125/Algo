class Solution {
public:
    /**
     * @param n: the value from 1 - n
     * @param value: the value of coins
     * @param amount: the number of coins
     * @return: how many different value
     */
    int backPackVIII(int n, vector<int> &value, vector<int> &amount) {

        int len = value.size();
        if(len == 0) return 0;
        if(len != amount.size()) return 0;

        // Prior len items can make value n
        vector<vector<bool>> dp(len + 1, vector<bool>(n + 1, false));
        // To make value 0, 0 coins can make that
        dp[0][0] = true;

        for(int i = 1; i <= len; ++i) {
            for(int j = 0; j <= n; ++j) {
                if(j == 0) {
                    dp[i][j] = true;
                    continue;
                }
                int maxCount = amount[i-1];
                for(int k = 0; k <= maxCount; ++k) {
                    if(k * value[i-1] <= j) {
                        dp[i][j] = dp[i][j] | dp[i-1][j-k * value[i-1]];
                        if(dp[i][j]) {break;}
                    }
                }
            }
        }

        int count = 0;
        for(int i = 1; i <= n; ++i) {
            if(dp[len][i]){++count;}
        }
        return count;
    }
};

// Just need to know for each size, if there is a solution, Time O(M*N), space O(M)
class Solution {
public:
    /**
     * @param n: the value from 1 - n
     * @param value: the value of coins
     * @param amount: the number of coins
     * @return: how many different value
     */
    int backPackVIII(int n, vector<int> &value, vector<int> &amount) {

        int len = value.size();
        if(len == 0) return 0;
        if(len != amount.size()) return 0;

        // Prior len items can make value n
        vector<bool> dp(n + 1, false);
        // To make value 0, 0 coins can make that
        dp[0] = true;

        for(int i = 0; i < len; ++i) {
            vector<int> cnt(n + 1, 0);
            // check for each number of it can make one size smaller than n
            for(int j = value[i]; j <= n; ++j) {
                if(dp[j-value[i]] && !dp[j] & cnt[j - value[i]] < amount[i]) {
                    cnt[j] += cnt[j - value[i]] + 1;
                    dp[j] = true;
                }
            }
        }

        int count = 0;
        for(int i = 1; i <= n; ++i) {
            if(dp[i]){++count;}
        }
        return count;
    }
};