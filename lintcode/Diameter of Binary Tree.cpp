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
    int height(TreeNode * root) {
        if(root == nullptr) return 0;
        return 1 + std::max(height(root->left), height(root->right));
    }
public:
    /**
     * @param root: a root of binary tree
     * @return: return a integer
     */
    int diameterOfBinaryTree(TreeNode * root) {
        if(root == nullptr) return 0;

        auto lHeight = height(root->left);
        auto rHeight = height(root->right);

        return lHeight + rHeight;
    }
};