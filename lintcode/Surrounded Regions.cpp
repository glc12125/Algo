class Solution {
private:
    int m_xMoves[4] = {-1, 0, 1, 0};
    int m_yMoves[4] = {0, 1, 0, -1};
    int m_rowSize;
    int m_colSize;
    int m_edgeValue;
    std::vector<int> m_fathers;

    int unionFind(int x) {
        if(m_fathers[x] == x || m_fathers[x] == m_edgeValue) return m_fathers[x];
        m_fathers[x] = unionFind(m_fathers[x]);
        return m_fathers[x];
    }

    int unionMerge(int x, int y) {
        auto xFather = unionFind(x);
        auto yFather = unionFind(y);
        if(xFather != yFather) {
            m_fathers[yFather] = xFather;
        }
    }

    bool isEdge(int i, int j) {
        return (i == 0 || i == m_rowSize - 1 || j == 0 || j == m_colSize - 1);
    }

    struct Point {
        int m_x;
        int m_y;
        Point() = default;
        Point(int x, int y) : m_x(x), m_y(y) {}
    };

    bool isValid(const Point& point){
        return (-1 < point.m_x && point.m_x < m_rowSize && -1 < point.m_y && point.m_y < m_colSize);
    }

    int getKey(const Point& point) {
        return point.m_x * m_colSize + point.m_y;
    }
public:
    /*
     * @param board: board a 2D board containing 'X' and 'O'
     * @return: nothing
     */
    void surroundedRegions(vector<vector<char>> &board) {
        m_rowSize = board.size();
        if(m_rowSize == 0) return;
        m_colSize = board[0].size();
        if(m_colSize == 0) return;
        m_edgeValue = m_rowSize * m_colSize;

        m_fathers.resize(m_edgeValue + 1);
        std::vector<Point> Os;
        for(int i = 0; i < m_rowSize; ++i) {
            for(int j = 0; j < m_colSize; ++j) {
                if(board[i][j] == 'O') {
                    int key = i*m_colSize+j;
                    if(isEdge(i, j)) m_fathers[key] = m_edgeValue;
                    else m_fathers[key] = key;
                    Os.push_back(Point(i, j));
                }
            }
        }

        for(const auto& point : Os) {
            int key = getKey(point);
            if(unionFind(key) == m_edgeValue) continue;
            for(int i = 0; i < 4; ++i) {
                Point next(point.m_x + m_xMoves[i], point.m_y + m_yMoves[i]);
                if(!isValid(next)) continue;
                if(board[next.m_x][next.m_y] == 'X') continue;
                int neighbourKey = getKey(next);
                unionMerge(neighbourKey, key);
            }
        }

        for(const auto& point : Os) {
            int key = getKey(point);
            if(unionFind(key) == m_edgeValue) continue;
            board[point.m_x][point.m_y] = 'X';
        }
    }
};

// BFS
class Solution {
private:
    int m_xMoves[4] = {-1, 0, 1, 0};
    int m_yMoves[4] = {0, 1, 0, -1};
    int m_rowSize;
    int m_colSize;

    bool isEdge(int i, int j) {
        return (i == 0 || i == m_rowSize - 1 || j == 0 || j == m_colSize - 1);
    }

    struct Point {
        int m_x;
        int m_y;
        Point() = default;
        Point(int x, int y) : m_x(x), m_y(y) {}
    };

    bool isValid(const Point& point){
        return (-1 < point.m_x && point.m_x < m_rowSize && -1 < point.m_y && point.m_y < m_colSize);
    }

    int getKey(const Point& point) {
        return point.m_x * m_colSize + point.m_y;
    }
public:
    /*
     * @param board: board a 2D board containing 'X' and 'O'
     * @return: nothing
     */
    void surroundedRegions(vector<vector<char>> &board) {
        m_rowSize = board.size();
        if(m_rowSize == 0) return;
        m_colSize = board[0].size();
        if(m_colSize == 0) return;

        std::queue<Point> q;
        std::unordered_set<int> visited;
        for(int r = 0; r < m_rowSize; ++r) {
            for(int c = 0; c < m_colSize; ++c) {
                if(board[r][c] == 'X') continue;
                Point point(r, c);
                int key = getKey(point);
                if(visited.count(key) > 0) continue;
                q.push(point);
                visited.insert(key);
                std::vector<Point> candidates;
                candidates.push_back(point);
                bool connectToEdge = isEdge(point.m_x, point.m_y) ? true : false;
                while(!q.empty()) {
                    const auto& curr = q.front();
                    q.pop();
                    for(int i = 0; i < 4; ++i) {
                        Point next(curr.m_x + m_xMoves[i], curr.m_y + m_yMoves[i]);
                        if(!isValid(next)) continue;
                        if(board[next.m_x][next.m_y] == 'X') continue;
                        int nextKey = getKey(next);
                        if(visited.count(nextKey) > 0) continue;
                        if(isEdge(next.m_x, next.m_y)) connectToEdge = true;
                        q.push(next);
                        visited.insert(nextKey);
                        candidates.push_back(next);
                    }
                }
                if(!connectToEdge) {
                    for(const auto& point : candidates) {
                        board[point.m_x][point.m_y] = 'X';
                    }
                }
            }
        }

    }
};