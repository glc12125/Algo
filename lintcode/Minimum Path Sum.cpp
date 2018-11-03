class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        if(n == 0) return 0;

        //vector<vector<int> > f(m, vector<int>(n));

        vector<vector<int> > f(2, vector<int>(n));
        int prev = 0;
        int curr = 0;

        for(int i = 0; i < m; ++i) {
            prev = curr;
            curr = 1 - curr;
            for(int j = 0; j < n; ++j) {
                if(i == 0 && j == 0) {
                    f[curr][0] = grid[0][0];
                    continue;
                }

                f[curr][j] = INT_MAX;
                if(i > 0) f[curr][j] = std::min(f[prev][j] + grid[i][j], f[curr][j]);

                if(j > 0) f[curr][j] = std::min(f[curr][j-1] + grid[i][j], f[curr][j]);
            }
        }

        return f[curr][n-1];
    }
};