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

    int maxSubArray(const vector<int>& nums) {
        int len = nums.size();
        vector<int> prefixSums(len + 1, 0);
        for(int i = 1; i < len + 1; ++i) {
            prefixSums[i] = prefixSums[i-1] + nums[i-1];
        }

        int min = INT_MAX;
        int max = INT_MIN;
        for(int i = 0; i < len + 1; ++i) {
            max = std::max(max, prefixSums[i] - min);
            min = std::min(min, prefixSums[i]);
        }
        return max;
    }
public:
    /**
     * @param matrix: the given matrix
     * @return: the largest possible sum
     */
    int maxSubmatrix(vector<vector<int>> &matrix) {
        int rowLen = matrix.size();
        if(rowLen == 0) return 0;
        int colLen = matrix[0].size();
        if(colLen == 0) return 0;

        const auto& prefixSumMatrix = generateMatrixPrefixSum(matrix);
        int maxSum = INT_MIN;
        for(int upperI = 0; upperI < rowLen; ++upperI) {
            for(int lowerI = upperI; lowerI < rowLen; ++lowerI) {
                auto A = getOneDimensionA(prefixSumMatrix, lowerI, upperI);
                maxSum = std::max(maxSum, maxSubArray(A));
            }
        }

        return maxSum;
    }
};