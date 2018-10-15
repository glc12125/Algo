/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */


class Solution {
private:
    std::unordered_map<DirectedGraphNode*, DirectedGraphNode*> m_fathers;

    DirectedGraphNode* findFather(DirectedGraphNode* son) {
        if(m_fathers[son] == son) return son;
        m_fathers[son] = findFather(m_fathers[son]);
        return m_fathers[son];
    }

    bool find(DirectedGraphNode* left, DirectedGraphNode* right) {
        return findFather(left) == findFather(right);
    }

    void unionGraph(DirectedGraphNode* node, DirectedGraphNode* toMergeNode) {
        auto nodeFather = findFather(node);
        auto toMergeNodeFather = findFather(toMergeNode);
        if(nodeFather != toMergeNodeFather) {
            m_fathers[toMergeNodeFather] = nodeFather;
        }
    }
public:
    /*
     * @param nodes: a array of Directed graph node
     * @return: a connected set of a directed graph
     */
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode*> nodes) {
        if(nodes.size() == 0) return std::vector<std::vector<int> > ();

        for(auto node : nodes) m_fathers[node] = node;

        for(auto node : nodes) {
            for(auto neighbor : node->neighbors) {
                unionGraph(neighbor, node);
            }
        }

        std::unordered_map<DirectedGraphNode*, std::vector<int> > fatherToNodes;
        for(auto node : nodes) {
            fatherToNodes[findFather(node)].push_back(node->label);
        }
        std::vector<std::vector<int> > results;
        for(auto& i : fatherToNodes) {
            auto& answer = i.second;
            std::sort(answer.begin(), answer.end());
            results.push_back(answer);
        }
        return results;
    }
};