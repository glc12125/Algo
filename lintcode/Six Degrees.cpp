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
     * @param graph: a list of Undirected graph node
     * @param s: Undirected graph node
     * @param t: Undirected graph nodes
     * @return: an integer
     */
    int sixDegrees(vector<UndirectedGraphNode*> graph, UndirectedGraphNode* s, UndirectedGraphNode* t) {
        if(s == nullptr || t == nullptr || graph.size() == 0) return -1;
        if(s == t) return 0;

        std::queue<UndirectedGraphNode*> q;
        q.push(s);
        std::unordered_set<UndirectedGraphNode*> visited;
        visited.insert(s);
        int degrees = 0;
        while(!q.empty()) {
            int len = q.size();
            while(len > 0) {
                auto curr = q.front();
                q.pop();
                if(curr == t) return degrees;
                for(auto neighbor : curr->neighbors) {
                    if(visited.count(neighbor) == 0) {
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
                --len;
            }
            ++degrees;
        }
        
        return -1;
    }
};