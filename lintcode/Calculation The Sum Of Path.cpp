/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
private:
    const int MOD = 1e9 + 7;

     void dpHelper(vector<vector<int>>& dp, int startI, int startJ, int endI, int endJ, int l, int w, int initialCount) {
        dp[startI][startJ] = initialCount;
        for(int i = startI; i <= endI; ++i) {
            for(int j = startJ; j <= endJ; ++j) {
                if(i == startI) {
                    dp[i][j] = initialCount;
                    continue;
                }

                if(j == startJ) {
                    dp[i][j] = initialCount;
                    continue;
                }

                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
                if(i == endI && j == endJ) {
                    break;
                }
            }
        }

        for(int i = endI + 1; i <= l; ++i) {
            dp[i][endJ] = dp[endI][endJ];
        }
        for(int j = endJ + 1; j <= w; ++j) {
            dp[endI][j] = dp[endI][endJ];
        }
     }
public:
    /**
     * @param l: The length of the matrix
     * @param w: The width of the matrix
     * @param points: three points
     * @return: The sum of the paths sum
     */
    long long calculationTheSumOfPath(int l, int w, vector<Point> &points) {
        int minX = INT_MAX;
        int minY = INT_MAX;
        for(const auto& point : points) {
            minX = std::min(minX, point.x);
            minY = std::min(minY, point.y);
        }

        sort(points.begin(), points.end(), [] (const Point & p1, const Point& p2) {
            if(p1.x != p2.x) {
                return p1.x < p2.x;
            } else {
                return p1.y < p2.y;
            }
        });

        if(minX < points[0].x || minY < points[0].y) { return 0; }

        vector<vector<int>> dp(l + 1, vector<int>(w + 1, 0));
        int startCount = 1;
        int startI = 1;
        int startJ = 1;
        for(const auto& point : points) {
            dpHelper(dp, startI, startJ, point.x, point.y, l, w, startCount);
            startI = point.x;
            startJ = point.y;
            startCount = dp[startI][startJ];
        }

        dpHelper(dp, startI, startJ, l, w, l, w, startCount);

        return dp[l][w];


    }
};