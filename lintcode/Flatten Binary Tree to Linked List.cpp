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
    TreeNode * m_last;
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode * root) {
        if(root == nullptr) return;
        
        if(m_last != nullptr) {
            m_last->left = nullptr;
            m_last->right = root;
        }
        m_last = root;
        auto right = root->right;
        flatten(root->left);
        flatten(right);
    }
};