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
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        TreeNode * curr = root;
        std::stack<TreeNode*> s;
        
        int rank = 1;
        while(curr != nullptr || !s.empty()) {
            if(curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            } else {
                curr = s.top();
                s.pop();
                if(rank++ == k) return curr->val;
                curr = curr->right;
            }
        }
    }
};