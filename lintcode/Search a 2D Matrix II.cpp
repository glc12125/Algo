class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int>> &matrix, int target) {
        int rowSize = matrix.size();
        if(rowSize == 0) return 0;
        int colSize = matrix[0].size();

        int counter = 0;
        int col = 0;
        int row = rowSize - 1;
        while(row > -1 && col < colSize){
            if(matrix[row][col] == target) {
                ++col;
                --row;
                ++counter;
            } else if (matrix[row][col] > target) {
                --row;
            } else {
                ++col;
            }
        }
        return counter;
    }
};