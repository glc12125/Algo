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
    int dfs(TreeNode* root) {
        if(root == nullptr) return 0;

        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);

        return max(0, max(leftSum, rightSum) + root->val);
    }
public:
    /**
     * @param root: the root of binary tree.
     * @return: An integer
     */
    int maxPathSum2(TreeNode * root) {
        if(root == nullptr) return 0;
        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);
        return root->val + std::max(0, std::max(leftSum, rightSum));
    }
};