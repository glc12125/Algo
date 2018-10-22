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

// Divide and conquer
class Solution {
private:
    int getMaxDepth(TreeNode * root) {
        if(root == nullptr) return 0;

        auto left = getMaxDepth(root->left);
        auto right = getMaxDepth(root->right);

        return std::max(left, right) + 1;
    }
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode * root) {
        return getMaxDepth(root);
    }
};

// DFS
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode * root) {
        if(root == nullptr) return 0;

        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// Iterative
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode * root) {
        if(root == nullptr) return 0;

        int maxDepth = 0;
        int depth = 1;
        auto node = root;
        std::stack<TreeNode*> s;
        std::stack<int> depthS;
        s.push(node);
        depthS.push(1);
        while(!s.empty()) {
            node = s.top();
            s.pop();
            depth = depthS.top();
            depthS.pop();
            maxDepth = std::max(maxDepth, depth);

            if(node->left != nullptr) {
                s.push(node->left);
                depthS.push(depth + 1);
            }
            if(node->right != nullptr) {
                s.push(node->right);
                depthS.push(depth + 1);
            }
        }
        return maxDepth;
    }
};