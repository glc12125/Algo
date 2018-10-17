class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        if(n == 0 || (edges.size() == 0 && n > 1)) return false;
        if(edges.size() == 0 && n == 1) return true;

        std::unordered_map<int, std::unordered_set<int> > neighbours;
        for(auto edge : edges) {
            neighbours[edge[0]].insert(edge[1]);
            neighbours[edge[1]].insert(edge[0]);
        }

        std::unordered_set<int> visited;
        std::queue<int> q;
        for(auto item : neighbours) {
            if(item.second.size() == 1) {
                q.push(item.first);
                visited.insert(item.first);
            }
        }

        int extractedNum = 0;
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            ++extractedNum;
            for(auto neighbour : neighbours[curr]) {
                neighbours[neighbour].erase(curr);
                if(visited.count(neighbour) == 0 && neighbours[neighbour].size() == 1) {
                    q.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }

        return extractedNum == n;
    }
};

// Union Find and DFS to be implemented
class Solution {
private:
    class UnionFind{
    public:
        std::vector<int> m_fathers;

        UnionFind(int n) {
            m_fathers.resize(n);
            for(int i = 0; i < n; ++i) {
                m_fathers[i] = i;
            }
        }

        int unionFind(int i) {
            if(m_fathers[i] == i) return i;
            m_fathers[i] = unionFind(m_fathers[i]);
            return m_fathers[i];
        }

        void unionMerge(int i, int j) {
            auto iFather = unionFind(i);
            auto jFather = unionFind(j);
            if(iFather != jFather) {
                m_fathers[iFather] = jFather;
            }
        }
    };
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        UnionFind uf(n);

        for(const auto& edge : edges) {
            if(uf.unionFind(edge[0]) == uf.unionFind(edge[1])) return false;
            uf.unionMerge(edge[0], edge[1]);
        }

        return edges.size() == n - 1;
    }
};