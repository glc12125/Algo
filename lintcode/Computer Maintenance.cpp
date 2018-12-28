// DP, Time O(n), space O(n)
class Solution {
public:
    /**
     * @param n: the rows of matrix
     * @param m: the cols of matrix
     * @param badcomputers: the bad computers
     * @return: The answer
     */
    int maintenance(int n, int m, vector<Point> &badcomputers) {
        if(n <= 0 || m <= 0) return 0;

        vector<vector<int>> dp(n, vector<int>(2));
        vector<vector<int>> minMaxPos(n, vector<int>(2));

        for(int i = 0; i < n; ++i) {
            minMaxPos[i][0] = INT_MAX;
            minMaxPos[i][1] = INT_MIN;
        }

        for(const auto& point : badcomputers) {
            int x = point.x;
            int y = point.y;
            minMaxPos[x][0] = std::min(minMaxPos[x][0], y);
            minMaxPos[x][1] = std::max(minMaxPos[x][1], y);
        }

        for(int i = 0; i < n; ++i) {
            int minPos = minMaxPos[i][0];
            int maxPos = minMaxPos[i][1];
            // when all computers are good on line i
            if(minPos == INT_MAX) {
                if(i == 0) {
                    dp[i][0] = 0;
                    dp[i][1] = m - 1;
                } else {
                    dp[i][0] = dp[i-1][0] + 1;
                    dp[i][1] = dp[i-1][1] + 1;
                }
                continue;
            } else {
                if(i == 0) {
                    dp[i][0] = maxPos + maxPos;
                    dp[i][1] = m - 1;
                    continue;
                }
            }

            dp[i][0] = std::min(dp[i-1][0] + maxPos + maxPos, dp[i-1][1] + m - 1) + 1;
            dp[i][1] = std::min(dp[i-1][1] + 2 * (m - 1 - minPos), dp[i-1][0] + m - 1) + 1;
        }
        return std::min(dp[n-1][0], dp[n-1][1]);
    }
};