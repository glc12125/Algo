/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */


class Solution {
public:
    /*
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        if(node == nullptr) return nullptr;
        
        std::queue<UndirectedGraphNode* > q;
        q.push(node);
        std::unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mapping;
        mapping[node] = new UndirectedGraphNode(node->label);
        while(!q.empty()) {
            auto current = q.front();
            q.pop();
            auto& clonedNode = mapping[current];
            for(auto n : current->neighbors) {
                if(mapping.count(n) > 0) {
                    clonedNode->neighbors.push_back(mapping[n]);
                } else {
                    q.push(n);
                    mapping[n] = new UndirectedGraphNode(n->label);
                    clonedNode->neighbors.push_back(mapping[n]);
                }
            }
        }
        
        return mapping[node];
    }
};