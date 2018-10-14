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