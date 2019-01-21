class Solution {
private:
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

        vector<vector<int>> answers(rowNum, vector<int>(colNum, 0));
        int totalHouseNum = 0;

        vector<Pos> houses;
        for(int x = 0; x < rowNum; ++x) {
            for(int y = 0; y < colNum; ++y) {
                if(grid[x][y] == 1) {
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
                        answers[cur.m_x][cur.m_y] += step;
                    }

                    for(int i = 0; i < 4; ++i) {
                        int nextX = cur.m_x + m_xMoves[i];
                        int nextY = cur.m_y + m_yMoves[i];
                        if(!isValidMove(nextX, nextY, rowNum, colNum)) continue;
                        int nextKey = getKey(nextX, nextY, colNum);
                        int nextType = grid[nextX][nextY];
                        if(visited.count(nextKey)) continue;
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
                if(grid[x][y] == 0) {
                    minimumTotalDistance = std::min(minimumTotalDistance, answers[x][y]);
                }
            }
        }

        return (minimumTotalDistance == INT_MAX ? -1 : minimumTotalDistance);
    }
};

// Time O(m*n) PrefixSum (DP)
class Solution {
public:
    /**
     * @param grid a 2D grid
     * @return an integer
     */
    int shortestDistance(vector<vector<int>>& grid) {
        // Write your code here
        int row = grid.size(), column = grid[0].size();
        if(row == 0 || column == 0 || !haveZero(grid, row, column)) {
            return -1;
        }

        vector<int> rowSum(row);
        vector<int> columnSum(column);
        for(int i = 0; i < row; i++)
            for(int j = 0; j < column; j++)
                if (grid[i][j] == 1) {
                    rowSum[i]++;
                    columnSum[j]++;
                }

        vector<int> costRow(row);
        vector<int> costColumn(column);
        getSumDistance(rowSum,row,costRow);
        getSumDistance(columnSum,column,costColumn);

        int cost = INT_MAX;
        for(int i = 0; i < row; i++)
            for(int j = 0; j < column; j++)
                if(grid[i][j] == 0 && cost > costRow[i] + costColumn[j]) {
                    cost = costRow[i] + costColumn[j];
                }
        return cost;
    }

    void getSumDistance(vector<int>& a, int n, vector<int>& cost) {
        vector<int> prefixSum1(n);
        vector<int> prefixSum2(n);
        /*
        第一阶段，处理前缀。
        prefixSum1记录数组 a 的前缀和，即:prefixSum1[i]=a[0]+a[1]+..+a[i].
        prefixSum2记录数组 prefixSum1 前缀和，prefixSum2即为前 i 个点到第 i 个点的代价和。
        */
        prefixSum1[0] = a[0];
        for(int i = 1; i < n; i++) {
            prefixSum1[i] = prefixSum1[i - 1] + a[i];
        }
        prefixSum2[0] = 0;
        for(int i = 1; i < n; i++) {
            prefixSum2[i] = prefixSum2[i - 1] + prefixSum1[i - 1];
        }

        for(int i = 0; i < n; i++) {
            cost[i] = prefixSum2[i];
        }

        /*
        第二阶段，处理后缀。
        prefixSum1记录数组 a 的后缀和，即:prefixSum1[i]=a[n-1]+a[n-2]+..+a[i].
        prefixSum2记录数组 prefixSum1 的后缀和，prefixSum2即为 i 之后的点到第 i 个点的代价和。
        */
        prefixSum1[n - 1] = a[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            prefixSum1[i] = prefixSum1[i + 1] + a[i];
        }
        prefixSum2[n - 1] = 0;
        for(int i = n - 2; i >= 0; i--) {
            prefixSum2[i] = prefixSum2[i + 1] + prefixSum1[i + 1];
        }

        for(int i = 0; i < n; i++) {
            cost[i] += prefixSum2[i];
        }

        /*
        cost[i] 即为a数组中所有点到第 i 点的代价和
        */
    }

    bool haveZero(vector<vector<int>>& grid, int row, int column) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (grid[i][j] == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};