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
    /**
     * @param graph: a list of Undirected graph node
     * @param A: nodeA
     * @param B: nodeB
     * @return:  the length of the shortest path
     */
    int shortestPath(vector<UndirectedGraphNode*> graph, UndirectedGraphNode* A, UndirectedGraphNode* B) {
        if(A == B) return 1;

        std::queue<UndirectedGraphNode*> startQ;
        startQ.push(A);
        std::queue<UndirectedGraphNode*> endQ;
        endQ.push(B);

        std::unordered_set<UndirectedGraphNode*> visitedStartSet;
        visitedStartSet.insert(A);
        std::unordered_set<UndirectedGraphNode*> visitedEndSet;
        visitedEndSet.insert(B);
        int step = 0;
        while(!startQ.empty() || !endQ.empty()) {
            int startQSize = startQ.size();
            int endQSize = endQ.size();

            ++step;
            for(int i = 0; i < startQSize; ++i) {
                auto curr = startQ.front();
                startQ.pop();
                for(auto neighbor : curr->neighbors) {
                    if(visitedStartSet.count(neighbor) > 0) continue;
                    else if (visitedEndSet.count(neighbor) > 0) return step;
                    else {
                        startQ.push(neighbor);
                        visitedStartSet.insert(neighbor);
                    }
                }
            }

            ++step;
            for(int i = 0; i < endQSize; ++i) {
                auto curr = endQ.front();
                endQ.pop();
                for(auto neighbor : curr->neighbors) {
                    if(visitedEndSet.count(neighbor) > 0) continue;
                    else if (visitedStartSet.count(neighbor) > 0) return step;
                    else {
                        endQ.push(neighbor);
                        visitedEndSet.insert(neighbor);
                    }
                }
            }
        }

        return -1;
    }
};