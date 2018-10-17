/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */


class Solution {
public:
    /*
     * @param nodes: a array of Undirected graph node
     * @return: a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*> nodes) {
        std::unordered_set<UndirectedGraphNode*> visited;

        std::vector<std::vector<int> > result;
        for(auto node : nodes) {
            if(visited.count(node) > 0) continue;
            std::queue<UndirectedGraphNode*> q;
            q.push(node);
            visited.insert(node);

            std::vector<int> answer;
            while(!q.empty()) {
                auto curr = q.front();
                q.pop();
                answer.push_back(curr->label);
                for(auto neighbor : curr->neighbors) {
                    if(visited.count(neighbor) == 0) {
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }

            std::sort(answer.begin(), answer.end());
            result.push_back(answer);
        }

        return result;
    }
};

// Union Find
class Solution {
private:
    struct UnionFind{
        std::unordered_map<UndirectedGraphNode *, UndirectedGraphNode*> m_fathers;

        UnionFind(const std::vector<UndirectedGraphNode*>& nodes) {
            for(auto node : nodes) m_fathers[node] = node;
        }

        UndirectedGraphNode* unionFind(UndirectedGraphNode* node) {
            if(m_fathers[node] == node) return node;
            m_fathers[node] = unionFind(m_fathers[node]);
            return m_fathers[node];
        }

        void unionMerge(UndirectedGraphNode* i, UndirectedGraphNode * j) {
            auto iFather = unionFind(i);
            auto jFather = unionFind(j);
            if(iFather != jFather) {
                m_fathers[iFather] = jFather;
            }
        }
    };
public:
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*> nodes) {
        if(nodes.size() == 0) return vector<vector<int>>();

        UnionFind uf(nodes);
        for(auto node : nodes) {
            for(auto neighbor : node->neighbors) {
                uf.unionMerge(node, neighbor);
            }
        }

        std::unordered_map<UndirectedGraphNode*, std::vector<int> > answers;
        for(auto node : nodes) {
            answers[uf.unionFind(node)].push_back(node->label);
        }

        std::vector<std::vector<int> > result;
        for(auto& answer: answers) {
            auto& sortedAnswer = answer.second;
            std::sort(sortedAnswer.begin(), sortedAnswer.end());
            result.push_back(sortedAnswer);
        }
        return result;

    }
};