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
     * @param root: the root
     * @return: the minimum difference between the values of any two different nodes in the tree
     */
    int minDiffInBST(TreeNode * root) {
        TreeNode * curr = root;
        std::stack<TreeNode *> s;
        int prevV = INT_MIN;
        int minDiff = INT_MAX;
        while(curr != nullptr || !s.empty()) {
            if(curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            } else {
                curr = s.top();
                s.pop();
                int diff = std::abs(curr->val - prevV);
                if (minDiff > diff) minDiff = diff;
                prevV = curr->val;
                curr = curr->right;
            }
        }
        return minDiff;
    }
};

// Recursive approach

class Solution {
public:
    /**
     * @param root: the root
     * @return: the minimum difference between the values of any two different nodes in the tree
     */
    int minDiffInBST(TreeNode * root) {
        if(!root) return INT_MAX;
        TreeNode *pre=nullptr;
        int res=INT_MAX;
        helper(root, pre, res);
        return res;
    }
    void helper(TreeNode *root, TreeNode *&pre, int &res) {
        if(!root) return;
        helper(root->left, pre, res);
        if(pre) {
            int t=abs(pre->val-root->val);
            if(t<res) {
                res=t;
            }
        }  
        pre=root;
        helper(root->right, pre, res);
    }
};