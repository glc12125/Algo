class Solution {
private:
    struct Pos{
        int m_i;
        int m_j;
        Pos () = default;
        Pos(int i, int j) : m_i(i), m_j(j) {}
    };

    bool isValidMove(int i, int j, int rowSize, int colSize) {
        return (0 <= i && i < rowSize && 0 <= j && j < colSize);
    }

    int getKey(int i, int j, int colSize) {
        return i * colSize + j;
    }

    int m_iMoves[4] = {-1, 0, 1, 0};
    int m_jMoves[4] = {0, 1, 0, -1};

public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &rooms) {
        int rowSize = rooms.size();
        if(rowSize == 0) return;
        int colSize = rooms[0].size();
        if(colSize == 0) return;

        const int INF = 2147483647;
        queue<Pos> q;
        unordered_set<int> visited;
        for(int i = 0; i < rowSize; ++i) {
            for(int j = 0; j < colSize; ++j) {
                if(rooms[i][j] == 0) {
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
                rooms[curr.m_i][curr.m_j] = step;
                int currI = curr.m_i;
                int currJ = curr.m_j;
                q.pop();
                for(int k = 0; k < 4; ++k) {
                    int nextI = currI + m_iMoves[k];
                    int nextJ = currJ + m_jMoves[k];
                    if(!isValidMove(nextI, nextJ, rowSize, colSize)) continue;
                    int key = getKey(nextI, nextJ, colSize);
                    if(visited.count(key) > 0) continue;
                    if(rooms[nextI][nextJ] == INF) {
                        q.push(Pos(nextI, nextJ));
                        visited.insert(key);
                    }
                }
                --len;
            }
            ++step;
        }
    }
};