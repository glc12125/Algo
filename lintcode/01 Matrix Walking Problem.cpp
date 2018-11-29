class Solution {
public:
    typedef struct node {
        int x, y, state;
        node () {}
        node (int x, int y, int state): x(x), y(y), state(state) {}
    } node ;
    queue<node>q;
    int dis[1005][1005][2];
    int n, m;
    bool check(int x, int y) {
        if(x < 0 || x >= n || y < 0 || y >= m) {
            return false ;
        } else {
            return true;
        }
    }
    int getBestRoad(vector<vector<int>> &grid) {
        // Write your code here
        const int MAX = 1e9 + 7;
        int i, j;
        n = grid.size();
        m = grid[0].size();
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++)dis[i][j][0] = dis[i][j][1] = MAX;
        }
        q.push(node(0, 0, 0));
        dis[0][0][0] = 0;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        while(!q.empty()) {
            node now = q.front();
            q.pop();
            int x = now.x, y = now.y, state = now.state;
            for(i = 0; i < 4; i++) {
                int nextX = x + dx[i];
                int nextY = y + dy[i];
                int nextState = now.state;
                if(!check(nextX, nextY))continue;
                nextState = state + grid[nextX][nextY];
                if(nextState > 1 || dis[nextX][nextY][nextState] != MAX)continue;
                dis[nextX][nextY][nextState] = dis[x][y][state] + 1;
                q.push(node(nextX, nextY, nextState));
            }
        }
        int ans = min(dis[n - 1][m - 1][0], dis[n - 1][m - 1][1]);
        return ans == MAX ? -1 : ans;
    }
};