/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        int len = graph.size();
        if(len == 0) return {};

        std::unordered_map<DirectedGraphNode*, int> inDegrees;
        for(auto node : graph) {
            if(inDegrees.count(node) == 0) inDegrees[node] = 0;
            for(auto neighbour : node->neighbors) {
                ++inDegrees[neighbour];
            }
        }

        std::queue<DirectedGraphNode*> q;
        for(auto item : inDegrees) {
            if(item.second == 0) {
                q.push(item.first);
            }
        }

        std::vector<DirectedGraphNode*> result;
        while(!q.empty()) {
            auto current = q.front();
            q.pop();
            result.push_back(current);
            for(auto neighbour : current->neighbors) {
                if(--inDegrees[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        return result;
    }
};

// DFS
class Solution {
private:
    void dfs(DirectedGraphNode * node, std::unordered_map<DirectedGraphNode*, int>& inDegrees, std::vector<DirectedGraphNode*>& result) {
        result.push_back(node);
        --inDegrees[node];

        for(auto neighbour : node->neighbors) {
            if(--inDegrees[neighbour] == 0) {
                dfs(neighbour, inDegrees, result);
            }
        }
    }
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        int len = graph.size();
        if(len == 0) return {};

        std::unordered_map<DirectedGraphNode*, int> inDegrees;
        for(auto node : graph) {
            if(inDegrees.count(node) == 0) inDegrees[node] = 0;
            for(auto neighbour : node->neighbors) {
                ++inDegrees[neighbour];
            }
        }

        std::vector<DirectedGraphNode*> result;
        for(auto item : inDegrees) {
            if(item.second == 0) {
                dfs(item.first, inDegrees, result);
            }
        }

        return result;
    }
};