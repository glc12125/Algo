class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        if(n == 0) return 0;

        vector<vector<int>> f(n+1, vector<int>(3));
        f[0][0] = 0;
        f[0][1] = 0;
        f[0][2] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < 3; ++j) {
                f[i][j] = INT_MAX;
                for (int k = 0; k < 3; ++k) {
                    if(k != j && f[i-1][k] + costs[i - 1][j] < f[i][j]) {
                        f[i][j] = f[i-1][k] + costs[i - 1][j];
                    }
                }
            }
        }

        int result = f[n][0];
        for(int i = 1; i < 3; ++i) {
            result = std::min(result, f[n][i]);
        }
        return result;
    }
};