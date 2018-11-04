class Solution {
private:
    struct Point{
        int m_r;
        int m_c;
        Point() = default;
        Point(int r, int c) : m_r(r), m_c(c) {}
    };

    vector<Point> getIndexes(const vector<vector<int>> & matrix) {
        int rLen = matrix.size();
        int cLen = matrix[0].size();

        vector<Point> result;
        for(int i = 0; i < rLen; ++i) {
            for(int j = 0; j < cLen; ++j) {
                if(matrix[i][j] != 0) result.push_back(Point(i, j));
            }
        }
        return result;
    }
public:
    /**
     * @param A: a sparse matrix
     * @param B: a sparse matrix
     * @return: the result of A * B
     */
    vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
        int rLen = A.size();
        int cLen = B[0].size();

        const auto& aIndexes = getIndexes(A);
        const auto& bIndexes = getIndexes(B);
        vector<vector<int>> product(rLen, vector<int>(cLen, 0));

        for(const auto& pA : aIndexes) {
            for(const auto& pB : bIndexes) {
                if(pA.m_c == pB.m_r) {
                    product[pA.m_r][pB.m_c] += A[pA.m_r][pA.m_c] * B[pB.m_r][pB.m_c];
                }
            }
        }

        return product;
    }
};