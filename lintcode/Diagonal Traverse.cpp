class Solution {
private:
    struct Pos{
        int m_i;
        int m_j;
        Pos() = default;
        Pos(int i, int j) : m_i(i), m_j(j) {}
    };

    int m_iMoves[2] = {0, 1};
    int m_jMoves[2] = {1, 0};

    bool isValidMove(int i, int j, int rowSize, int colSize) {
        return (0 <= i && i < rowSize && 0 <= j && j < colSize);
    }

    int getKey(int i, int j, int colSize) {
        return i * colSize + j;
    }

public:
    /**
     * @param matrix: a 2D array
     * @return: return a list of integers
     */
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
        int rowSize = matrix.size();
        if(rowSize == 0) return {};
        int colSize = matrix[0].size();
        if(colSize == 0) return {};

        bool downFirst = false;
        queue<Pos> q;
        q.push(Pos(0, 0));
        unordered_set<int> visited;
        visited.insert(getKey(0, 0, colSize));

        vector<int> result;
        while(!q.empty()) {
            int len = q.size();
            downFirst = !downFirst;
            vector<Pos> buffer;
            while(len > 0) {
                auto curr = q.front();
                buffer.push_back(curr);
                q.pop();
                for(int k = 0; k < 2; ++k) {
                    int nextI = curr.m_i + m_iMoves[k];
                    int nextJ = curr.m_j + m_jMoves[k];
                    if(!isValidMove(nextI, nextJ, rowSize, colSize)) continue;
                    int key = getKey(nextI, nextJ, colSize);
                    if(visited.count(key)) continue;
                    visited.insert(key);
                    q.push(Pos(nextI, nextJ));
                }
                --len;
            }
            if(downFirst) {
                reverse(buffer.begin(), buffer.end());
            }
            for(int i = 0; i < buffer.size(); ++i) {
                result.push_back(matrix[buffer[i].m_i][buffer[i].m_j]);
            }
        }
        return result;
    }
};