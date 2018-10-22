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
    std::stack<TreeNode*> m_s;

    void createStack(TreeNode * root, TreeNode * p) {
        if(root == nullptr || p == nullptr) return;

        while(root != nullptr) {
            m_s.push(root);
            if(p->val >= root->val) root = root->right;
            else root = root->left;
        }
    }

    TreeNode * predecessor() {
        if(m_s.empty()) return nullptr;

        auto curr = m_s.top();
        auto node = curr;

        if(node->left == nullptr) {
            m_s.pop();
            while(!m_s.empty() && m_s.top()->left == node) {
                node = m_s.top();
                m_s.pop();
            }
        } else {
            node = node->left;
            while(node != nullptr) {
                m_s.push(node);
                node = node->right;
            }
        }

        return curr;
    }
public:
    /**
     * @param root: the given BST
     * @param p: the given node
     * @return: the in-order predecessor of the given node in the BST
     */
    TreeNode * inorderPredecessor(TreeNode * root, TreeNode * p) {
        createStack(root, p);

        if(m_s.empty()) return nullptr;
        auto result = predecessor();
        while(result != nullptr && result->val >= p->val) {
            result = predecessor();
        }
        return result;

    }
};