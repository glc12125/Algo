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

// Using binary search
class Solution {
private:
    typedef bool(*CheckFuncPtr)(vector<vector<char>>&, int);
    
    static bool checkColumn(vector<vector<char>>& image, int col) {
        for (int i = 0; i < image.size(); i++) {
            if (image[i][col] == '1') {
                return true;
            }
        }
        return false;
    }
    
    static bool checkRow(vector<vector<char>>& image, int row) {
        for (int j = 0; j < image[0].size(); j++) {
            if (image[row][j] == '1') {
                return true;
            }
        }
        return false;
    }
    
    void search(vector<vector<char>>& image, int start, int end, int& finalStart, int& finalEnd, CheckFuncPtr check, bool smallerSide) {
        finalStart = start;
        finalEnd = end;
        int mid;
        while (finalStart + 1 < finalEnd) {
            mid = finalStart + (finalEnd - finalStart) / 2;
            if ((*check)(image, mid)) {
                smallerSide ? finalEnd = mid : finalStart = mid;
            } else {
                smallerSide ? finalStart = mid : finalEnd = mid;
            }
        }
    }
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        // Write your code here
        int m = image.size();
        if (m == 0)
            return 0;
        int n = image[0].size();
        if (n == 0)
            return 0;

        int start;
        int end;
        search(image, y, n-1, start, end, &Solution::checkColumn, false);
        int right = checkColumn(image, end) ? end : start;
        
        search(image, 0, y, start, end, &Solution::checkColumn, true);
        int left = checkColumn(image, start) ? start : end;
        
        search(image, x, m-1, start, end, &Solution::checkRow, false);
        int down = checkRow(image, end) ? end : start;
        
        search(image, 0, x, start, end, &Solution::checkRow, true);
        int up = checkRow(image, start) ? start : end;
        
        return (right - left + 1) * (down - up + 1);
    }
};