class NumMatrix {
private:
    int m_rowSize;
    int m_colSize;
    vector<vector<int> > m_bitree;
    vector<vector<int> > m_original;

    int lowbit(int x) {
        return x & (-x);
    }

    void add(int x, int y, int delta) {
        ++x;
        ++y;
        for(int i = x; i <= m_rowSize; i += lowbit(i)) {
            for(int j = y; j <= m_colSize; j += lowbit(j)) {
                m_bitree[i][j] += delta;
            }
        }
    }

    int query(int x, int y) {
        ++x;
        ++y;
        int res = 0;
        for(int i = x; i > 0; i -= lowbit(i)) {
            for(int j = y; j > 0; j -= lowbit(j)) {
                res += m_bitree[i][j];
            }
        }
        return res;
    }

public:
    NumMatrix(vector<vector<int>> matrix) {
        m_rowSize = matrix.size();
        m_colSize = matrix[0].size();
        m_bitree = vector<vector<int> >(m_rowSize + 1, vector<int>(m_colSize + 1, 0));
        m_original = matrix;

        for(int i = 0; i < m_rowSize; ++i) {
            for(int j = 0; j < m_colSize; ++j) {
                add(i, j, m_original[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        int delta = val - m_original[row][col];
        m_original[row][col] = val;
        add(row, col, delta);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return query(row2, col2) - query(row1 - 1, col2) - query(row2, col1 - 1) + query(row1 - 1, col1 - 1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */