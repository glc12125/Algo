class Solution {
private:
    int m_xMoves[4] = {-1, 0, 1, 0};
    int m_yMoves[4] = {0, 1, 0, -1};

    struct Pos{
        int m_x;
        int m_y;
        Pos(int x, int y) : m_x(x) , m_y(y) {}
        Pos() = default;
    };

    bool isValid(int rowLen, int colLen, const Pos& next) {
        return (-1 < next.m_x && next.m_x < rowLen && -1 < next.m_y && next.m_y < colLen);
    }
public:
    /**
     * @param grid: a 2D integer grid
     * @return: an integer
     */
    int zombie(vector<vector<int>> &grid) {
        int rowLen = grid.size();
        if(rowLen == 0) return 0;
        int colLen = grid[0].size();
        if(colLen == 0) return 0;

        std::queue<Pos> q;
        for(int i = 0; i < rowLen; ++i) {
            for(int j = 0; j < colLen; ++j) {
                if(grid[i][j] == 1) q.push(Pos(i,j));
            }
        }

        int days = -1;
        while(!q.empty()) {
            int currLen = q.size();
            while(currLen > 0){
                const auto& pos = q.front();
                q.pop();
                for(int i = 0; i < 4; ++i) {
                    Pos next(pos.m_x + m_xMoves[i], pos.m_y + m_yMoves[i]);
                    if(isValid(rowLen, colLen, next) && grid[next.m_x][next.m_y] == 0) {
                        q.push(next);
                        grid[next.m_x][next.m_y] = 1;
                    }
                }
                --currLen;
            }
            ++days;
        }

        for(int i = 0; i < rowLen; ++i) {
            for(int j = 0; j < colLen; ++j) {
                if(grid[i][j] == 0) return -1;
            }
        }

        return days;
    }
};