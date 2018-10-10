class Solution {
private:
    int xMoves[4] = {-1, 0, 1, 0};
    int yMoves[4] = {0, 1, 0, -1};
    void updateMinMax(vector<vector<char>> &image, int rowSize, int colSize, int x, int y, int& minX, int& maxX, int& minY, int& maxY) {
        if(x < 0 || x > rowSize - 1 || y < 0 || y > colSize - 1) return;
        if(image[x][y] == '0') return;
        
        minX = std::min(minX, x);
        maxX = std::max(maxX, x);
        minY = std::min(minY, y);
        maxY = std::max(maxY, y);
        image[x][y] = '0';
        for(int i = 0; i < 4; ++i) {
            updateMinMax(image, rowSize, colSize, x + xMoves[i], y + yMoves[i], minX, maxX, minY, maxY);
        }
    }
public:
    /**
     * @param image: a binary matrix with '0' and '1'
     * @param x: the location of one of the black pixels
     * @param y: the location of one of the black pixels
     * @return: an integer
     */
    int minArea(vector<vector<char>> &image, int x, int y) {
        int rowSize = image.size();
        if(rowSize == 0) return 0;
        int colSize = image[0].size();
        int minX = INT_MAX;
        int maxX = INT_MIN;
        int minY = INT_MAX;
        int maxY = INT_MIN;
        updateMinMax(image, rowSize, colSize, x, y, minX, maxX, minY, maxY);
        
        return (maxX - minX + 1) * (maxY - minY + 1);
    }
};