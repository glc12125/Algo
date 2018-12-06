class Solution {
    void dfs1(int x, int f, vector<vector<pair<int, int>>> &g, vector<int> &np, vector<long long> &dp) {
        np[x] = 1;
        dp[x] = 0;
        for (int i = 0; i < g[x].size(); i++) {
            int y = g[x][i].first;
            if (y == f) {
                continue;
            }
            dfs1(y, x, g, np, dp);
            np[x] += np[y];
            dp[x] += dp[y] + (long long)g[x][i].second * np[y];
        }
    }
    int dfs2(int x, int f, long long sum, vector<vector<pair<int, int>>> &g, vector<int> &np, vector<long long> &dp, long long &ans, int &idx, int n) {
        for (int i = 0; i < g[x].size(); i++) {
            int y = g[x][i].first;
            if (y == f) {
                continue;
            }
            long long nextSum = dp[y] + (sum - dp[y] - (long long)np[y] * g[x][i].second) + (long long)(n - np[y]) * g[x][i].second;
            if (nextSum < ans || (nextSum == ans && x < idx)) {
                ans = nextSum;
                idx = y;
            }
            dfs2(y, x, nextSum, g, np, dp, ans, idx, n);
        }
    }

public:
    int getFermatPoint(vector<int> &x, vector<int> &y, vector<int> &d) {
        // Write your code here
        int n = x.size() + 1;
        vector<vector<pair<int, int>>> g(n + 1);
        for (int i = 0; i < x.size(); i++) {
            g[x[i]].push_back(make_pair(y[i], d[i]));
            g[y[i]].push_back(make_pair(x[i], d[i]));
        }
        vector<int> np(n + 1, 0);
        vector<long long> dp(n + 1, 0);
        dfs1(1, 0, g, np, dp);
        long long ans = dp[1];
        int idx = 1;
        dfs2(1, 0, dp[1], g, np, dp, ans, idx, n);
        return idx;
    }
};