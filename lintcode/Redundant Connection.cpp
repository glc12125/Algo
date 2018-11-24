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

    bool unionMerge(int son1, int son2) {
        int root1 = unionFind(son1);
        int root2 = unionFind(son2);
        if(root1 != root2) {
            m_roots[root1] = root2;
            return true;
        }
        return false;
    }
public:
    /**
     * @param edges: List[List[int]]
     * @return: List[int]
     */
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int eLen = edges.size();
        if(eLen == 0) return {};

        initUnion(eLen);

        for(const auto& edge : edges) {
            if(!unionMerge(edge[0], edge[1])) return edge;
        }
    }
};