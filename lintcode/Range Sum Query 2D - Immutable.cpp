class NumMatrix {
private:
    vector<vector<int> > m_prefixSum;
public:
    NumMatrix(vector<vector<int>> matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();

        m_prefixSum.resize(rowSize + 1, vector<int>(colSize + 1, 0));

        for(int i = 1; i <= rowSize; ++i) {
            for(int j = 1; j <= colSize; ++j) {
                m_prefixSum[i][j] = m_prefixSum[i-1][j] + m_prefixSum[i][j-1] - m_prefixSum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return m_prefixSum[row2 + 1][col2 + 1] - m_prefixSum[row1][col2 + 1] - m_prefixSum[row2 + 1][col1] + m_prefixSum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */