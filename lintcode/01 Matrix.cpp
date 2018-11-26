class Solution {
private:
    struct Pos{
        int m_x;
        int m_y;
        Pos() = default;
        Pos(int x, int y) : m_x(x), m_y(y) {}
    };

    bool isValidNext(int x, int y, int rowSize, int colSize) {
        return (0 <= x && x < rowSize && 0 <= y && y < colSize);
    }

    int getKey(int x, int y, int colSize) {
        return x * colSize + y;
    }

    int m_xMoves[4] = {-1, 0, 1, 0};
    int m_yMoves[4] = {0, 1, 0, -1};
public:
    /**
     * @param matrix: a 0-1 matrix
     * @return: return a matrix
     */
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        int rowSize = matrix.size();
        if(rowSize == 0) return {{}};
        int colSize = matrix[0].size();
        if(colSize == 0) return {{}};

        queue<Pos> q;
        unordered_set<int> visited;
        vector<vector<int>> result(rowSize, vector<int>(colSize, 0));
        for(int i = 0; i < rowSize; ++i) {
            for(int j = 0; j < colSize; ++j) {
                if(matrix[i][j] == 0) {
                    q.push(Pos(i, j));
                    visited.insert(getKey(i, j, colSize));
                }
            }
        }

        int step = 0;
        while(!q.empty()) {
            int len = q.size();
            while(len > 0) {
                auto curr = q.front();
                q.pop();
                if(matrix[curr.m_x][curr.m_y] == 1) {
                    result[curr.m_x][curr.m_y] = step;
                }
                for(int k = 0; k < 4; ++k) {
                    int nextX = curr.m_x + m_xMoves[k];
                    int nextY = curr.m_y + m_yMoves[k];
                    if(!isValidNext(nextX, nextY, rowSize, colSize)) continue;
                    int key = getKey(nextX, nextY, colSize);
                    if(visited.count(key)) continue;
                    if(matrix[nextX][nextY] == 0) continue;
                    visited.insert(key);
                    q.push(Pos(nextX, nextY));
                }
                --len;
            }
            ++step;
        }

        return result;
    }
};