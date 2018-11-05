class Solution {
private:
    vector<int> compress(const vector<vector<int>> &matrix, int lower, int upper) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();

        vector<int> result(colSize, 0);
        for(int j = 0; j < colSize; ++j) {
            for(int i = lower; i <= upper; ++i) {
                result[j] += matrix[i][j];
            }
        }
        return result;
    }

    bool subArraySumZero(const vector<int>& line, vector<int>& indexes) {
        int len = line.size();
        vector<int> prefixSum(len + 1, 0);
        for(int i = 1; i <= len; ++i) {
            prefixSum[i] = prefixSum[i-1] + line[i-1];
        }

        unordered_map<int, int> existingSum;
        for(int i = 0; i <= len; ++i) {
            if(existingSum.count(prefixSum[i])) {
                indexes[0] = existingSum[prefixSum[i]] == 0 ? 0 : existingSum[prefixSum[i]];
                indexes[1] = i - 1;
                return true;
            }
            existingSum[prefixSum[i]] = i;
        }
        return false;
    }
public:
    /*
     * @param matrix: an integer matrix
     * @return: the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>> &matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();

        for(int i = 0; i < rowSize; ++i) {
            for(int j = i; j < rowSize; ++j) {
                const auto& line = compress(matrix, i, j);
                vector<int> cols(2);
                if(subArraySumZero(line, cols)) {
                    return {{i, cols[0]}, {j, cols[1]}};
                }
            }
        }
        return {};
    }
};