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
    int getMinDepth(TreeNode* root) {
        if(root == nullptr) return INT_MAX;

        int leftMin = getMinDepth(root->left);
        int rightMin = getMinDepth(root->right);

        int min = std::min(leftMin, rightMin);
        if(min == INT_MAX) return 1;
        else return min + 1;
    }
public:
    /**
     * @param root: The root of binary tree
     * @return: An integer
     */
    int minDepth(TreeNode * root) {
        int depth = getMinDepth(root);
        if(depth == INT_MAX) return 0;
        else return depth;
    }
};