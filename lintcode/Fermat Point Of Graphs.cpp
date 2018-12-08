/*
Tree dynamic programming
dp[i] represents the aggregated distance from i to all the substree nodes with i as the root，dp[i] = sum(dp[j] + size[j] * d(i, j))
size[i] represents the subtree node number with i as the size[i] = sum(size[j]) + 1。

This question is a weighted version of "Sums of Distances in Tree"
With a similar solution。we choose a node as root and calculate the aggregated distance for all the
other nodes. We also need to calculate the substree size for each node. The transition equation is：

dp[i] = dp[j] - size[i] * w(i, j) + (n - size[i]) * w(i, j), where j is i's parent
the distance between subtree nodes and i(as root) is decrease by size[i] * w(i, j) compared to that with j as root.
The distance between all the other nodes that are not subtree with i as root increases by (n - size[i]) * w(i, j)
where n is the number of nodes，and w(i, j) means the weight between i and j。We do dfs from top to bottom.
The space and time complexity are both O(n).
*/
class Solution {
class Solution {
public:
    /**
    * @param x: The end points set of edges
    * @param y: The end points set of edges
    * @param d: The length of edges
    * @return: Return the index of the fermat point
    */
    int getFermatPoint(vector<int> &x, vector<int> &y, vector<int> &d)
    {
        //acyclic connected graph, V = E + 1
        int n = x.size() + 1;
        vector<vector<pair<int, int>>> g(n + 1);
        for (int i = 0; i < x.size(); ++i)
        {
            int u = x[i], v = y[i], w = d[i];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        vector<long long> dp(n + 1, 0);
        vector<int> sz(n + 1, 0);
        countSubTree(0, 1, g, dp, sz);
        long long minDist = dp[1];
        int idx = 1;
        findPoint(0, 1, g, sz, dp[1], idx, minDist);
        return idx;
    }

private:
    void countSubTree(int from, int to, vector<vector<pair<int, int>>>& g, vector<long long>& dp, vector<int>& sz)
    {
        sz[to] = 1;
        for (const auto& adj : g[to])
        {
            int v = adj.first;
            long long w = adj.second;
            if (v != from)
            {
                countSubTree(to, v, g, dp, sz);
                sz[to] += sz[v];
                dp[to] += dp[v] + sz[v] * w;
            }
        }
    }

    void findPoint(int from, int to, vector<vector<pair<int, int>>>& g, vector<int>& sz, long long dist, int& res, long long& minDist)
    {
        int n = sz.size() - 1;
        for (const auto& adj : g[to])
        {
            int v = adj.first;
            long long w = adj.second;
            if (v != from)
            {
                long long currDist = dist - sz[v] * w + (n - sz[v]) * w;
                if (currDist < minDist)
                {
                    minDist = currDist;
                    res = v;
                }
                findPoint(to, v, g, sz, currDist, res, minDist);
            }
        }
    }
};