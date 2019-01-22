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
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode * root) {
        if(root == nullptr) return;

        auto curr = root;
        stack<TreeNode *> s;
        while(!s.empty() || curr != nullptr) {
            if(curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            } else {
                curr = s.top();
                s.pop();
                auto temp = curr->right;
                curr->right = curr->left;
                curr->left = temp;
                curr = curr->left;
            }
        }
    }
};