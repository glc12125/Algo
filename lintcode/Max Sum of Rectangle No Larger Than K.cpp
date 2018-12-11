// time O(M*N*(N+N*N))
class Solution {
private:
    vector<vector<int> > generateMatrixPrefixSum(vector<vector<int>> &matrix) {
        int rowLen = matrix.size();
        int colLen = matrix[0].size();
        vector<vector<int> > prefixSumMatrix(rowLen + 1, vector<int>(colLen, 0));

        for(int i = 1; i <= rowLen; ++i) {
            for(int j = 0; j < colLen; ++j) {
                prefixSumMatrix[i][j] = prefixSumMatrix[i-1][j] + matrix[i-1][j];
            }
        }
        return prefixSumMatrix;
    }

    vector<int> getOneDimensionA(const vector<vector<int> >& prefixSumMatrix, int lowerRow, int upperRow) {
        int colLen = prefixSumMatrix[0].size();

        vector<int> A(colLen, 0);
        for(int i = 0; i < colLen; ++i) {
            A[i] = prefixSumMatrix[lowerRow + 1][i] - prefixSumMatrix[upperRow][i];
        }
        return A;
    }

    int maxSubArray(const vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> prefixSums(len + 1, 0);
        for(int i = 1; i < len + 1; ++i) {
            prefixSums[i] = prefixSums[i-1] + nums[i-1];
        }

        int max = INT_MIN;
        for(int i = 1; i <= len; ++i) {
            for(int j = 0; j < i; ++j) {
                int subSum = prefixSums[i] - prefixSums[j];
                if(subSum > k) continue;
                max = std::max(max, subSum);
            }
        }
        return max;
    }
public:
    /**
     * @param matrix: a 2D matrix
     * @param k: an integer
     * @return: the max sum of a rectangle in the matrix such that its sum is no larger than k
     */
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        int rowSize = matrix.size();
        if(rowSize == 0) return 0;
        int colSize = matrix[0].size();
        if(colSize == 0) return 0;

        const auto& prefixSum = generateMatrixPrefixSum(matrix);
        int maxSum = INT_MIN;
        for(int upperRow = 0; upperRow < rowSize; ++upperRow) {
            for(int lowerRow = upperRow; lowerRow < rowSize; ++lowerRow) {
                const auto& one = getOneDimensionA(prefixSum, lowerRow, upperRow);
                maxSum = std::max(maxSum, maxSubArray(one, k));
                if(maxSum == k) return k;
            }
        }
        return maxSum;
    }
};

// Range sum query 2d - Immutable
class Solution {
private:
    int sumRegion(const vector<vector<int>>& prefixSum, int row1, int col1, int row2, int col2) {
        return prefixSum[row2 + 1][col2 + 1] - prefixSum[row1][col2 + 1] - prefixSum[row2 + 1][col1] + prefixSum[row1][col1];
    }
public:
    /**
     * @param matrix: a 2D matrix
     * @param k: an integer
     * @return: the max sum of a rectangle in the matrix such that its sum is no larger than k
     */
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        int rowSize = matrix.size();
        if(rowSize == 0) return 0;
        int colSize = matrix[0].size();
        if(colSize == 0) return 0;

        vector<vector<int>> prefixSum(rowSize + 1, vector<int>(colSize + 1, 0));

        for(int i = 1; i <= rowSize; ++i) {
            for(int j = 1; j <= colSize; ++j) {
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + matrix[i-1][j-1];
            }
        }

        int maxSum = INT_MIN;
        for(int upperRow = 0; upperRow < rowSize; ++upperRow) {
            for(int upperCol = 0; upperCol < colSize; ++upperCol) {
                for(int lowerRow = upperRow; lowerRow < rowSize; ++lowerRow) {
                    for(int lowerCol = upperCol; lowerCol < colSize; ++lowerCol) {
                        int sum = sumRegion(prefixSum, upperRow, upperCol, lowerRow, lowerCol);
                        if(sum > k) continue;
                        if(maxSum == k) return k;
                        maxSum = std::max(maxSum, sum);
                    }
                }
            }
        }
        return maxSum;
    }
};