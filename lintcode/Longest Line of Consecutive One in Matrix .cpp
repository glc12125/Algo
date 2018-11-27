class Solution {
public:
    /**
     * @param M: the 01 matrix
     * @return: the longest line of consecutive one in the matrix
     */
    int longestLine(vector<vector<int>> &M) {
        int rowSize = M.size();
        if(rowSize == 0) return 0;
        int colSize = M[0].size();
        if(colSize == 0) return 0;

        vector<vector<int>> up(rowSize, vector<int>(colSize, 0));
        vector<vector<int>> left(rowSize, vector<int>(colSize, 0));
        vector<vector<int>> diag(rowSize, vector<int>(colSize, 0));

        int maxLen = 0;

        for(int i = 0; i < rowSize; ++i) {
            for(int j = 0; j < colSize; ++j) {
                if(M[i][j] == 1) {
                    up[i][j] = 1;
                    left[i][j] = 1;
                    diag[i][j] = 1;
                    if(i > 0 && j > 0 && M[i-1][j-1] == 1) diag[i][j] = std::max(diag[i][j], diag[i-1][j-1] + 1);
                    if(j > 0 && M[i][j-1] == 1) left[i][j] = std::max(left[i][j], left[i][j-1] + 1);
                    if(i > 0 && M[i-1][j] == 1) up[i][j] = std::max(up[i][j], up[i-1][j] + 1);
                } else {
                    up[i][j] = 0;
                    left[i][j] = 0;
                    diag[i][j] = 0;
                    if(i > 0) up[i][j] = up[i-1][j];
                    if(j > 0) left[i][j] = left[i][j-1];
                    if(i > 0 && j > 0) diag[i][j] = diag[i-1][j-1];
                }
                maxLen = std::max(maxLen, std::max(up[i][j], std::max(left[i][j], diag[i][j])));
            }
        }

        return maxLen;
    }
};

// With rolling array
class Solution {
public:
    /**
     * @param M: the 01 matrix
     * @return: the longest line of consecutive one in the matrix
     */
    int longestLine(vector<vector<int>> &M) {
        int rowSize = M.size();
        if(rowSize == 0) return 0;
        int colSize = M[0].size();
        if(colSize == 0) return 0;

        vector<vector<int>> up(2, vector<int>(colSize, 0));
        vector<vector<int>> left(rowSize, vector<int>(2, 0));
        vector<vector<int>> diag(2, vector<int>(2, 0));

        int maxLen = 0;

        for(int i = 0; i < rowSize; ++i) {
            for(int j = 0; j < colSize; ++j) {
                if(M[i][j] == 1) {
                    up[i%2][j] = 1;
                    left[i][j%2] = 1;
                    diag[i%2][j%2] = 1;
                    if(i > 0 && j > 0 && M[i-1][j-1] == 1) diag[i%2][j%2] =  diag[(i-1)%2][(j-1)%2] + 1;
                    if(j > 0 && M[i][j-1] == 1) left[i][j%2] = left[i][(j-1)%2] + 1;
                    if(i > 0 && M[i-1][j] == 1) up[i%2][j] = up[(i-1)%2][j] + 1;
                }
                maxLen = std::max(maxLen, std::max(up[i%2][j], std::max(left[i][j%2], diag[i%2][j%2])));
            }
        }

        return maxLen;
    }
};