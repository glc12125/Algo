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
    int m_minimumSum = INT_MAX;
    TreeNode * m_result = nullptr;
    
    int findMinimum(TreeNode * node) {
        if(node == nullptr) return 0;
        
        auto leftSum = findMinimum(node->left);
        auto rightSum = findMinimum(node->right);
        
        if(leftSum + rightSum + node->val <= m_minimumSum){
            m_minimumSum = leftSum + rightSum + node->val;
            m_result = node;
        }
        
        return leftSum + rightSum + node->val;
    }
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the minimum subtree
     */
    TreeNode * findSubtree(TreeNode * root) {
        findMinimum(root);
        return m_result;
    }
};