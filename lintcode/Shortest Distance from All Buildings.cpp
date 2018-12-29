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

    bool isValidMove(int x, int y, int width, int height) {
        return 0 <= x && x < height && 0 <= y && y < width;
    }

    int getKey(int x, int y, int width) {
        return x * width + y;
    }

public:
    /**
     * @param grid: the 2D grid
     * @return: the shortest distance
     */
    int shortestDistance(vector<vector<int>> &grid) {
        int height = grid.size();
        if(height == 0) { return 0; }
        int width = grid[0].size();
        if(width == 0) { return 0; }

        vector<Pos> emptyLands;
        int buildingNum = 0;
        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                if(grid[i][j] == 1) {
                    ++buildingNum;
                } else if (grid[i][j] == 0) {
                    emptyLands.emplace_back(Pos(i, j));
                }
            }
        }

        //std::cout << "emptyLands.size(): " << emptyLands.size() << ", buildingNum: " << buildingNum << "\n";
        int minSteps = INT_MAX;
        for(const auto& pos : emptyLands) {
            queue<Pos> q;
            unordered_set<int> visitedPos;
            q.push(pos);
            visitedPos.insert(getKey(pos.m_x, pos.m_y, width));
            int step = 0;
            int totalStep = 0;
            int buildingNumCopy = buildingNum;
            while(!q.empty()) {
                int len = q.size();
                while(len > 0) {
                    auto curr = q.front();
                    q.pop();
                    if(grid[curr.m_x][curr.m_y] == 1) {
                        totalStep += step;
                        if(--buildingNumCopy == 0) {
                            break;
                        }
                        --len;
                        continue;
                    }
                    for(int i = 0; i < 4; ++i) {
                        int nextX = curr.m_x + m_xMoves[i];
                        int nextY = curr.m_y + m_yMoves[i];
                        if(!isValidMove(nextX, nextY, width, height)) {continue;}
                        int nextKey = getKey(nextX, nextY, width);
                        if(visitedPos.count(nextKey) > 0 || grid[nextX][nextY] == 2) {continue;}
                        visitedPos.insert(nextKey);
                        q.emplace(nextX, nextY);
                    }
                    --len;
                }
                ++step;
            }
            //std::cout << "start from [" << pos.m_x << ", " << pos.m_y << "], buildingNumCopy: " << buildingNumCopy << "\n";
            if(buildingNumCopy == 0) {
                minSteps = std::min(minSteps, totalStep);
            }
        }

        return minSteps;
    }
};