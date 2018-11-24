/*
DP, time O(n^3)
4.我们也不知道选哪儿，假设我们选了一个位置 i，然后没选中、要去左边或者右边，它的 worst now (即选了now位置以后的worst case)
就是 worst now = now + worst(left cost, right cost)，同理用这种办法可以求出 worst left 和 worst right。也就是说，
worst now 取决于 worst left 和 worst right 和 now。然后知道了 worst now1, worst now2...worst now n，
从中最小的一个就是 worst 1~n 中的best。这样一看我们就知道要用 DP！
5.值得注意的是，worst now 只取一边，即最坏的一边，而不是两边都取！因为玩家也不是傻子，玩家用的方法肯定是最优的方法，只不过最优的方法碰到了最坏的情况而已。
*/
class Solution {
public:
    /**
     * @param n: An integer
     * @return: how much money you need to have to guarantee a win
     */
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));

        for(int len = 1; len <= n; ++len) {
            int end = n - len + 1;
            for(int i = 1; i <= end; ++i) {
                int j = i + len - 1;
                if(i == j) { // can guess directly, without fine
                    dp[i][j] = 0;
                    continue;
                }
                for(int k = i; k <= j; ++k) {
                    if(k == i) {
                        dp[i][j] = std::min(dp[i][j], k + dp[i+1][j]);
                        continue;
                    }
                    if(k == j) {
                        dp[i][j] = std::min(dp[i][j], k + dp[i][j-1]);
                        continue;
                    }

                    dp[i][j] = std::min(dp[i][j], k + std::max(dp[k+1][j], dp[i][k-1]));
                }
            }
        }

        return dp[1][n];
    }
};