class Solution {
public:
    /**
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int rowSize = matrix.size();
        if(rowSize == 0) return false;
        int colSize = matrix[0].size();

        int start = 0;
        int end = rowSize - 1;
        int mid;
        while(start < end) {
            mid = (start + end) / 2;
            if(matrix[mid][0] == target) return true;
            if(matrix[mid][0] < target) start = mid + 1;
            else end = mid - 1;
        }

        int row;
        if(matrix[start][0] > target) row = start - 1;
        else if (matrix[start][0] < target) row = start;
        else return true;

        start = 0;
        end = colSize - 1;
        while(start < end) {
            mid = (start + end) / 2;
            if(matrix[row][mid] == target) return true;
            if(matrix[row][mid] < target) start = mid + 1;
            else end = mid - 1;
        }
        return (matrix[row][start] == target);
    }
};