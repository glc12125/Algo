class Solution {
private:
    int getMaxArea(const vector<int>& heights) {
        int len = heights.size();
        stack<int> s;
        int maxArea = 0;
        for(int i = 0; i <= len; ++i) {
            int curr = (i == len ? -1 : heights[i]);
            while(!s.empty() && curr <= heights[s.top()]) {
                int h = heights[s.top()];
                s.pop();
                int w = s.empty() ? i : i - s.top() - 1;
                maxArea = std::max(maxArea, w * h);
            }
            s.push(i);
        }
        return maxArea;
    }
public:
    /**
     * @param matrix: a boolean 2D matrix
     * @return: an integer
     */
    int maximalRectangle(vector<vector<bool>> &matrix) {
        int rowSize = matrix.size();
        if(rowSize == 0) return 0;
        int colSize = matrix[0].size();
        if(colSize == 0) return 0;

        vector<vector<int>> heights(rowSize + 1, vector<int>(colSize, 0));
        for(int i = 0; i < rowSize; ++i) {
            for(int j = 0; j < colSize; ++j) {
                if(matrix[i][j]) {
                    heights[i+1][j] = heights[i][j] + 1;
                } else {
                    heights[i+1][j] = 0;
                }
            }
        }
        int maxArea = 0;
        for(int i = 0; i < rowSize; ++i) {
            maxArea = std::max(maxArea, getMaxArea(heights[i+1]));
        }
        return maxArea;
    }
};