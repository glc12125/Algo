/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
private:
    struct NodeWithIndex{
        TreeNode * m_node;
        int m_index;
        NodeWithIndex() = default;
        NodeWithIndex(TreeNode* node, int index) : m_node(node), m_index(index) {}
    };
public:
    /**
     * @param root: the root of tree
     * @return: the vertical order traversal
     */
    vector<vector<int>> verticalOrder(TreeNode * root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;

        map<int, vector<int>> travelMap;
        queue<NodeWithIndex> q;
        q.push(NodeWithIndex(root, 0));
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            travelMap[curr.m_index].push_back(curr.m_node->val);
            if(curr.m_node->left != nullptr) q.push(NodeWithIndex(curr.m_node->left, curr.m_index - 1));
            if(curr.m_node->right != nullptr) q.push(NodeWithIndex(curr.m_node->right, curr.m_index + 1));
        }

        for(auto level : travelMap) {
            result.push_back(level.second);
        }
        return result;
    }
};