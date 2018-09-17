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
    int dfs(TreeNode * node, int& total) {
        if(node == nullptr) return 0;
        int left = node->left ? dfs(node->left, total) : 0;
        int right = node->right? dfs(node->right, total) : 0;
        
        int totalL = node->left && node->val == node->left->val ? 1 + left : 0;
        int totalR = node->right && node->val == node->right->val ? 1 + right : 0;
        
        total = std::max(total, totalL + totalR);
        
        return std::max(totalL, totalR);
    }
public:
    /**
     * @param root: 
     * @return: the length of the longest path where each node in the path has the same value
     */
    int longestUnivaluePath(TreeNode * root) {
        if(root == nullptr) return 0;
        else {
            int total = 0;
            dfs(root, total);
            return total;
        }
    }
};