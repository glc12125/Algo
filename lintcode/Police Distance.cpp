class Solution {
private:
    struct Pos{
        int m_x;
        int m_y;
        Pos() = default;
        Pos(int x, int y) : m_x(x), m_y(y) {}
    };

    int m_xMoves[4] = {-1, 0, 1, 0};
    int m_yMoves[4] = {0, 1, 0, -1};

    bool isValidMove(int x, int y, int rowSize, int colSize) {
        return (0 <= x && x < rowSize && 0 <= y && y < colSize);
    }

    int getKey(int x, int y, int colSize) {
        return x * colSize + y;
    }

public:
    /**
     * @param matrix : the martix
     * @return: the distance of grid to the police
     */
    vector<vector<int>> policeDistance(vector<vector<int>> &matrix ) {

        int rowSize = matrix.size();
        if(rowSize == 0) return {{}};
        int colSize = matrix[0].size();
        if(colSize == 0) return {{}};

        vector<vector<int>> result(rowSize, vector<int>(colSize, 0));
        queue<Pos> q;
        unordered_set<int> visitedEmpty;
        for(int i = 0; i < rowSize; ++i) {
            for(int j = 0; j < colSize; ++j) {
                if(matrix[i][j] == 1) {
                    q.push(Pos(i, j));
                    result[i][j] = 0;
                } else if (matrix[i][j] == -1) {
                    result[i][j] = -1;
                }
            }
        }

        int step = 1;
        while(!q.empty()) {
            int len = q.size();
            while(len > 0) {
                auto curr = q.front();
                q.pop();
                for(int i = 0; i < 4; ++i) {
                    int nextX = curr.m_x + m_xMoves[i];
                    int nextY = curr.m_y + m_yMoves[i];
                    if(!isValidMove(nextX, nextY, rowSize, colSize)) continue;
                    int content = matrix[nextX][nextY];
                    if(content != 0) continue;
                    int key = getKey(nextX, nextY, colSize);
                    if(visitedEmpty.count(key)) continue;
                    visitedEmpty.insert(key);
                    result[nextX][nextY] = step;
                    q.push(Pos(nextX, nextY));
                }

                --len;
            }
            ++step;
        }
        return result;
    }
};