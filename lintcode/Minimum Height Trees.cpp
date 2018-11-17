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

        // because we start from all leaves, depending on whether ther is odd or even nodes on path
        // there will be 2(even) or 1(odd) nodes left in the queue for the last step and they will
        // be the roots as the MHT
        while (n > 2) {
            int size = q.size();
            n -= size;
            for(int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                const auto& neighbours = adj[node];
                for(auto neighbour : neighbours) {
                    adj[neighbour].erase(node);
                    if(adj[neighbour].size() == 1) q.push(neighbour);
                }
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