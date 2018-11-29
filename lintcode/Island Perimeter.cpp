class Solution {
private:
    int checkValue(const vector<vector<int>> &grid, int i, int j, int h, int w) {
        return  (i-1>-1?grid[i-1][j]:0) +
                (j+1<w?grid[i][j+1]:0) +
                (i+1<h?grid[i+1][j]:0) +
                (j-1>-1?grid[i][j-1]:0);
    }
public:
    /**
     * @param grid: a 2D array
     * @return: the perimeter of the island
     */
    int islandPerimeter(vector<vector<int>> &grid) {
        auto height = grid.size();
        auto width = grid[0].size();
        int total = 0;
        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                if(grid[i][j] == 1) total += 4 - checkValue(grid, i, j, height, width);
            }
        }
        return total;
    }
};