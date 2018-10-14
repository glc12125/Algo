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