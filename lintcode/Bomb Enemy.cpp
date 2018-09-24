// Time complexity O(m*n), space O(m*n), iterative approach
class Solution {

public:
    /**
     * @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
     * @return: an integer, the maximum enemies you can kill using one bomb
     */
    int maxKilledEnemies(vector<vector<char>> &grid) {
        int rowSize = grid.size();
        if(rowSize == 0) return 0;
        int colSize = grid[0].size();
        
        int up[rowSize][colSize] = {0};
        int left[rowSize][colSize] = {0};
        int right[rowSize][colSize] = {0};
        int down[rowSize][colSize] = {0};
        
        for(int i = 0; i < rowSize; ++i) {
            for(int j = 0; j <colSize; ++j) {
                if(grid[i][j] == 'W') {
                    up[i][j] = 0;
                    left[i][j] = 0;
                } else {
                    up[i][j] = (grid[i][j] == 'E' ? 1 : 0) + (i > 0 ? up[i-1][j] : 0);
                    left[i][j] = (grid[i][j] == 'E' ? 1 : 0) + (j > 0 ? left[i][j-1] : 0);
                }
            }
        }
        
        for(int i = rowSize - 1; i > -1; --i) {
            for(int j = colSize - 1; j > -1; --j) {
                if(grid[i][j] == 'W') {
                    down[i][j] = 0;
                    right[i][j] = 0;
                } else {
                    down[i][j] = (grid[i][j] == 'E' ? 1 : 0) + (i < rowSize - 1 ? down[i+1][j] : 0);
                    right[i][j] = (grid[i][j] == 'E' ? 1 : 0) + (j <colSize - 1 ? right[i][j+1] : 0);
                }
            }
        }
        
        int max = 0;
        for(int i = 0; i < rowSize; ++i) {
            for(int j = 0; j <colSize; ++j) {
                if(grid[i][j] == '0') {
                    int count = up[i][j] + down[i][j] + left[i][j] + right[i][j];
                    max = std::max(max, count);
                }
            }
        }
        
        return max;
    }
};

// Using rolling array to optimize memory,t
// ime complexity O(m*n), spaceO(n), iterative approach
class Solution {

public:
    /**
     * @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
     * @return: an integer, the maximum enemies you can kill using one bomb
     */
    int maxKilledEnemies(vector<vector<char>> &grid) {
        int rowSize = grid.size();
        if(rowSize == 0) return 0;
        int colSize = grid[0].size();
        if(colSize == 0) return 0;
        
        int cols[colSize] = {0};
        int rows = 0;
        int max = 0;
        for(int i = 0; i < rowSize; ++i) {
            for(int j = 0; j < colSize; ++j) {
                if(j == 0 || grid[i][j-1] == 'W') {
                    rows = 0;
                    int k = j;
                    while(k < colSize && grid[i][k] != 'W') {
                        if(grid[i][k] == 'E') ++rows;
                        ++k;
                    }
                }
                
                if(i == 0 || grid[i-1][j] == 'W') {
                    cols[j] = 0;
                    int k = i;
                    while(k < rowSize && grid[k][j] != 'W') {
                        if(grid[k][j] == 'E') ++cols[j];
                        ++k;
                    }
                }
                
                if(grid[i][j] == '0') {
                    max = std::max(max, rows + cols[j]);
                }
            }
        }
        
        return max;
    }
};