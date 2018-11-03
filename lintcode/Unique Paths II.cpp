class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0) return 0;
        int n = obstacleGrid[0].size();
        if(n == 0) return 0;

        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n-1] == 1) return 0;

        std::vector<std::vector<int>> f(m, vector<int>(n, 0));

        f[0][0] = 1;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(obstacleGrid[i][j] == 1) {
                    f[i][j] = 0;
                    continue;
                }

                if(i > 0) f[i][j] += f[i-1][j];
                if(j > 0) f[i][j] += f[i][j-1];
            }
        }

        return f[m-1][n-1];
    }
};