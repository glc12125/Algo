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
    int dfs(TreeNode* root, int& maxSum) {
        if(root == nullptr) return 0;

        int sum = root->val;
        int leftSum = dfs(root->left, maxSum);
        int rightSum = dfs(root->right, maxSum);

        if(leftSum > 0) {
            sum += leftSum;
        }
        if(rightSum > 0) {
            sum += rightSum;
        }

        maxSum = std::max(maxSum, sum);
        return max(0, max(leftSum, rightSum)) + root->val;
    }

public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode * root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }
};