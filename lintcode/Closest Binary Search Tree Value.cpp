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


// Get lower and upper bound and compare both difference

class Solution {
private:
    TreeNode* lowerBound(TreeNode* node, double target) {
        if (node == NULL) {
            return node;
        }
        
        if (target <= node->val) {
            return lowerBound(node->left, target);
        }
        
        TreeNode* lower = lowerBound(node->right, target);
        return (lower == NULL) ? node : lower;
        
    }

    TreeNode* upperBound(TreeNode* node, double target) {
        if (node == NULL) {
            return node;
        }
        
        if (target >= node->val) {
            return upperBound(node->right, target);
        }
        
        TreeNode* upper = upperBound(node->left, target);
        return (upper == NULL) ? node : upper;
        
    }
public:
    /**
     * @param root: the given BST
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    int closestValue(TreeNode * root, double target) {
        
        auto lower = lowerBound(root, target);
        auto upper = upperBound(root, target);
        
        if(lower == nullptr) return upper->val;
        if(upper == nullptr) return lower->val;
        return fabs(target - lower->val) < fabs(target - upper->val) ? lower->val :upper->val;
    }
};