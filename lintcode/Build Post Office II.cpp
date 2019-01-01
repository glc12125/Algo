class Solution {
private:
    struct Answer{
        int m_houseNum;
        int m_totalDistance;
        Answer() : m_houseNum(0), m_totalDistance(0) {}
    };

    struct Pos{
        int m_x;
        int m_y;
        Pos() : m_x(0) , m_y(0) {}
        Pos(int x, int y) : m_x(x), m_y(y) {}
    };

    bool isValidMove(int x, int y, int rowNum, int colNum) {
        return 0 <= x && x < rowNum && 0 <= y && y < colNum;
    }

    int getKey(int x, int y, int colNum) {
        return x * colNum + y;
    }

    int m_xMoves[4] = {-1, 0, 1, 0};
    int m_yMoves[4] = {0, 1, 0, -1};
public:
    /**
     * @param grid: a 2D grid
     * @return: An integer
     */
    int shortestDistance(vector<vector<int>> &grid) {
        int rowNum = grid.size();
        if(rowNum == 0) return -1;
        int colNum = grid[0].size();
        if(colNum == 0) return -1;

        vector<vector<Answer>> answers(rowNum, vector<Answer>(colNum));
        int totalHouseNum = 0;

        vector<Pos> houses;
        for(int x = 0; x < rowNum; ++x) {
            for(int y = 0; y < colNum; ++y) {
                if(grid[x][y] == 1) {
                    ++totalHouseNum;
                    houses.emplace_back(Pos(x, y));
                }
            }
        }

        for(const auto& pos : houses) {
            queue<Pos> q;
            unordered_set<int> visited;
            q.push(pos);
            visited.insert(getKey(pos.m_x, pos.m_y, colNum));

            int step = 0;
            while(!q.empty()) {
                int len = q.size();
                while(len > 0) {
                    auto cur = q.front();
                    q.pop();
                    if(grid[cur.m_x][cur.m_y] == 0) {
                        ++answers[cur.m_x][cur.m_y].m_houseNum;
                        answers[cur.m_x][cur.m_y].m_totalDistance += step;
                    }

                    for(int i = 0; i < 4; ++i) {
                        int nextX = cur.m_x + m_xMoves[i];
                        int nextY = cur.m_y + m_yMoves[i];
                        if(!isValidMove(nextX, nextY, rowNum, colNum)) continue;
                        int nextKey = getKey(nextX, nextY, colNum);
                        int nextType = grid[nextX][nextY];
                        if(visited.count(nextKey) || nextType == 1 || nextType == 2) continue;
                        visited.insert(nextKey);
                        q.emplace(nextX, nextY);
                    }
                    --len;
                }
                ++step;
            }
        }


        int minimumTotalDistance = INT_MAX;

        for(int x = 0; x < rowNum; ++x) {
            for(int y = 0; y < colNum; ++y) {
                if(answers[x][y].m_houseNum == totalHouseNum) {
                    minimumTotalDistance = std::min(minimumTotalDistance, answers[x][y].m_totalDistance);
                }
            }
        }

        return (minimumTotalDistance == INT_MAX ? -1 : minimumTotalDistance);
    }
};