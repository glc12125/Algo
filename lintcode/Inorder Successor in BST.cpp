/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
private:
    std::stack<TreeNode*> m_s;

    void createStack(TreeNode* root, TreeNode* p) {
        if(root == nullptr || p == nullptr) return;

        while(root != nullptr) {
            m_s.push(root);
            if(p->val < root->val) root = root->left;
            else root = root->right;
        }
    }

    TreeNode * successor(){
        if(m_s.empty()) return nullptr;
        auto curr = m_s.top();
        auto node = curr;

        if(node->right == nullptr) {
            m_s.pop();
            while(!m_s.empty() && m_s.top()->right == node) {
                node = m_s.top();
                m_s.pop();
            }
        } else {
            node = node->right;
            while(node != nullptr) {
                m_s.push(node);
                node = node->left;
            }
        }
        return curr;
    }
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        createStack(root, p);
        if(m_s.empty()) return nullptr;

        auto result = successor();
        while(result != nullptr && result->val <= p->val) result = successor();
        return result;
    }
};