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
     * @param graph: a list of Undirected graph node
     * @param values: a hash mapping, <UndirectedGraphNode, (int)value>
     * @param node: an Undirected graph node
     * @param target: An integer
     * @return: a node
     */
     UndirectedGraphNode* searchNode(vector<UndirectedGraphNode*>& graph,
                                    map<UndirectedGraphNode*, int>& values,
                                    UndirectedGraphNode* node,
                                    int target) {
        if(node == nullptr) return nullptr;
        std::queue<UndirectedGraphNode*> q;
        q.push(node);
        std::unordered_set<UndirectedGraphNode*> visited;
        visited.insert(node);
        while(!q.empty()) {
            int len = q.size();
            while(len > 0) {
                auto curr = q.front();
                q.pop();
                if(values[curr] == target) return curr;
                for(auto neighbor : curr->neighbors) {
                    if(visited.count(neighbor) == 0) {
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
                --len;
            }
        }
        return nullptr;
    }
};