public class Solution {
    /**
     * @param n: non-negative integer, n posts
     * @param k: non-negative integer, k colors
     * @return: an integer, the total number of ways
     */
    // public int numWays(int n, int k) {
    //     // write your code here

    //     // dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) * (k - 1)
    //     // dp[i][1] = dp[i - 1][0]
    //     int[][] dp = new int[n][2];
    //     for (int i = 0; i < n; i++) {
    //         if (i == 0) {
    //             dp[i][0] = k;
    //             dp[i][1] = 0;
    //             continue;
    //         }
    //         dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) * (k - 1);
    //         dp[i][1] = dp[i - 1][0];
    //     }
    //     return dp[n - 1][0] + dp[n - 1][1];

    // }

    public int numWays(int n, int k) {
        // write your code here

        int same = 0, diff = k;
        for (int i = 1; i < n; i++) {
            int tmp = diff;
            diff = (diff + same) * (k - 1);
            same = tmp;
        }
        return same + diff;

    }
}