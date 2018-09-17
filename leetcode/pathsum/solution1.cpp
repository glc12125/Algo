//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == 0) {
            return false;
        } 
        
        if (root->val == sum && root->left == NULL && root->right == NULL) {
            return true;
        }
        
        bool leftPath = false;
        if (root->left != 0) {
            leftPath = hasPathSum(root->left, sum - root->val);
        }
        bool rightPath = false;
        if (root->right != 0) {
            rightPath = hasPathSum(root->right, sum - root->val);
        }
        
        return leftPath || rightPath; 
    }
};