class Solution{
private:
    int m_xMoves[4] = {-1, 0, 1, 0};
    int m_yMoves[4] = {0, 1, 0, -1};

    void bfs(std::vector<std::vector<bool> > &grid, int rowLen, int colLen, int i, int j) {
        std::queue<std::pair<int, int> > q;
        q.push(std::pair<int, int>(i, j));
        grid[i][j] = 0;
        while(!q.empty()) {
            auto pos = q.front();
            q.pop();
            for(int delta = 0; delta < 4; ++delta) {
                int nextX = pos.first + m_xMoves[delta];
                int nextY = pos.second + m_yMoves[delta];
                if(!isValid(rowLen, colLen, nextX, nextY) || grid[nextX][nextY] == 0) continue;
                q.push(std::pair<int, int>(nextX, nextY));
                grid[nextX][nextY] = 0;
            }
        }
    }

    bool isValid(int rowLen, int colLen, int i, int j) {
        return (0 <= i && i <= rowLen - 1 && 0 <= j && j <= colLen - 1);
    }

public:

    int numIslands(vector<vector<bool>> &grid) {
        int rowLen = grid.size();
        if(rowLen == 0) return 0;
        int colLen = grid[0].size();
        if(colLen == 0) return 0;

        int islandNum = 0;
        for(int i = 0; i < rowLen; ++i) {
            for(int j = 0; j < colLen; ++j) {
                if(grid[i][j] == 1) {
                    bfs(grid, rowLen, colLen, i, j);
                    ++islandNum;
                }
            }
        }
        return islandNum;
    }

};

// Union find solution to be added
class Solution {
public:
    struct Graph{
        std::vector<int> m_root;
        int m_connected;

        Graph(int n) {
            m_root.reserve(n);
            for (int i = 0; i < n; ++i)
                m_root[i] = -1;
        }

        void setConnected(int n) {
            m_connected = n;
        }

        int find(int x) {
            if(m_root[x] < 0) return x;
            m_root[x] = find(m_root[x]);
            return m_root[x];
        }

        /*
         * @param a: An integer
         * @param b: An integer
         * @return: nothing
         */
        void connect(int a, int b) {
            // write your code here
            int rootA = find(a);
            int rootB = find(b);
            if(rootA == rootB) return;
            m_root[rootA] += m_root[rootB];
            m_root[rootB] = rootA;
            --m_connected;
        }

        /*
         * @return: An integer
         */
        int query() {
            return m_connected;
        }
    };

    int X[4] = {-1, 0, 1, 0};
    int Y[4] = {0, -1, 0, 1};
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands_unionFind(vector<vector<bool>> &grid) {
        auto rowSize = grid.size();
        if(rowSize == 0) return 0;
        auto colSize = grid[0].size();
        if(colSize == 0) return 0;

        Graph g(rowSize * colSize);

        int count = 0;
        for(size_t i = 0; i < rowSize; ++i){
            for(size_t j = 0; j < colSize; ++j) {
                if (grid[i][j]) ++count;
            }
        }

        g.setConnected(count);

        for(size_t i = 0; i < rowSize; ++i){
            for(size_t j = 0; j < colSize; ++j)
            {
                int number = i * colSize + j;
                if(grid[i][j]) {
                    /*for(int c = 0; c < 4; ++c){
                        auto deltaX = i+X[c];
                        auto deltaY = j+Y[c];
                        int x = ((deltaX > -1 && deltaX < rowSize) ? deltaX : i);
                        int y = ((deltaY > -1 && deltaY < colSize) ? deltaY : j);
                        if(grid[x][y]) g.connect(number, x * colSize + y);
                    }*/
                    if (i > 0 && grid[i - 1][j]) {
                        g.connect(i * colSize + j, (i - 1) * colSize + j);
                    }
                    if (i <  rowSize - 1 && grid[i + 1][j]) {
                        g.connect(i * colSize + j, (i + 1) * colSize + j);
                    }
                    if (j > 0 && grid[i][j - 1]) {
                        g.connect(i * colSize + j, i * colSize + j - 1);
                    }
                    if (j < colSize - 1 && grid[i][j + 1]) {
                        g.connect(i * colSize + j, i * colSize + j + 1);
                    }
                }
            }
        }
        return g.query();
    }
};