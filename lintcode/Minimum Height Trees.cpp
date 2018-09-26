class Solution {
public:
    /**
     * @param n: n nodes labeled from 0 to n - 1
     * @param edges: a undirected graph
     * @return:  a list of all the MHTs root labels
     */
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if(n == 1) return {0};

        std::vector<std::unordered_set<int>> adj(n);
        for(const auto& e : edges) {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }

        std::queue<int> q;
        for(int i = 0; i < n; ++i) {
            if(adj[i].size() == 1) q.push(i);
        }

        while (n > 2) {
            int size = q.size();
            n -= size;
            for(int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                const auto& neighbours = adj[node];
                auto firstNeighbour = *(neighbours.begin());
                adj[firstNeighbour].erase(node);
                if(adj[firstNeighbour].size() == 1) q.push(firstNeighbour);
            }
        }

        std::vector<int> result;
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            result.push_back(node);
        }

        return result;
    }
};