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
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    int closestValue(TreeNode * root, double target) {
        double minDiff = INT_MAX;
        int result = 0;
        TreeNode * curr = root;
        std::stack<TreeNode *> s;
        while(curr != nullptr || !s.empty()) {
            if(curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            } else {
                curr = s.top();
                s.pop();
                double diff = std::abs(target - curr->val); 
                if(minDiff > diff) {
                    minDiff = diff;
                    result = curr->val;
                }
                curr = curr->right;
            }
        }
        
        return result;
    }
};

// Recursive approach

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
    void dfs(TreeNode * node, double target, double& minDiff, int& val) {
        if(node == nullptr) return;
        
        dfs(node->left, target, minDiff, val);
        double diff = std::abs(target - node->val);
        if(diff < minDiff) {
            minDiff = diff;
            val = node->val;
        }
        dfs(node->right, target, minDiff, val);
    }
public:
    /**
     * @param root: the given BST
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    int closestValue(TreeNode * root, double target) {
        double minDiff = INT_MAX;
        int result = 0;
        dfs(root, target, minDiff, result);
        return result;
    }
};