// Time O(2Row + 2Col + Col * Row * log(Col + Row))
class Solution {
private:
    struct Cell{
        int m_r;
        int m_c;
        int m_height;
        Cell() = default;
        Cell(int r, int c, int height) : m_r(r), m_c(c), m_height(height) {}
    };

    struct CellCompare{
        bool operator()(const Cell& c1, const Cell& c2) const {
            return c1.m_height > c2.m_height;
        }
    };

    int m_rowMoves[4] = {-1, 0, 1, 0};
    int m_colMoves[4] = {0, 1, 0, -1};

    bool isValidNext(int r, int c, int rSize, int cSize) {
        return (0 <= r && r < rSize && 0 <= c && c < cSize);
    }
public:
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int trapRainWater(vector<vector<int>> &heights) {
        int rowLen = heights.size();
        if(rowLen == 0) return 0;
        int colLen = heights[0].size();
        if(colLen == 0) return 0;

        vector<vector<bool> > visited(rowLen, vector<bool>(colLen, false));
        priority_queue<Cell, vector<Cell>, CellCompare> q;
        for(int i = 0; i < rowLen; ++i) {
            visited[i][0] = true;
            visited[i][colLen - 1] = true;
            q.push(Cell(i, 0, heights[i][0]));
            q.push(Cell(i, colLen - 1, heights[i][colLen - 1]));
        }

        for(int j = 0; j < colLen; ++j) {
            visited[0][j] = true;
            visited[rowLen - 1][j] = true;
            q.push(Cell(0, j, heights[0][j]));
            q.push(Cell(rowLen - 1, j, heights[rowLen - 1][j]));
        }

        int total = 0;
        while(!q.empty()) {
            auto curr = q.top();
            q.pop();
            for(int i = 0; i < 4; ++i) {
                int nextRow = curr.m_r + m_rowMoves[i];
                int nextCol = curr.m_c + m_colMoves[i];
                if(!isValidNext(nextRow, nextCol, rowLen, colLen)) continue;
                if(visited[nextRow][nextCol]) continue;
                visited[nextRow][nextCol] = true;
                q.push(Cell(nextRow, nextCol, std::max(curr.m_height, heights[nextRow][nextCol])));
                total += std::max(0, curr.m_height - heights[nextRow][nextCol]);
            }
        }

        return total;
    }
};