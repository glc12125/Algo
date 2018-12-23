class Solution {
private:
    vector<int> m_roots;

    void initUnion(int n) {
        m_roots.resize(n + 1);
        for(int i = 1; i <= n; ++i) {
            m_roots[i] = i;
        }
    }

    int unionFind(int son) {
        if(son == m_roots[son]) return son;
        m_roots[son] = unionFind(m_roots[son]);
        return m_roots[son];
    }

    bool unionMerge(int to, int from) {
        int rootTo = unionFind(to);
        int rootFrom = unionFind(from);
        if(rootTo != rootFrom) {
            m_roots[rootTo] = rootFrom;
            return true;
        }
        return false;
    }
public:
    /**
     * @param edges: List[List[int]]
     * @return: return List[int]
     */
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        int num = edges.size();
        if(num == 0) return {};

        initUnion(num);

        unordered_map<int, int> from;
        vector<vector<int>> candidates;
        for(auto& edge : edges) {
            if(from.count(edge[1])) {
                candidates.push_back({from[edge[1]], edge[1]});
                candidates.push_back(edge);
                edge[1] = -1;
            } else {
                from[edge[1]] = edge[0];
            }
        }

        for(const auto& edge : edges) {
            if(edge[1] == -1) continue;

            if(!unionMerge(edge[1], edge[0])) {
                if(candidates.empty()) {
                    return edge;
                }
                return candidates[0];
            }
        }
        return candidates[1];
    }
};