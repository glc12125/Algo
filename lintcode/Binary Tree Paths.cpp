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
    std::vector<std::string> getPaths(TreeNode* root) {
        std::vector<std::string> result;
        if(root == nullptr) return result;

        auto leftPaths = getPaths(root->left);
        auto rightPaths = getPaths(root->right);

        for(const auto& path : leftPaths) result.push_back(std::to_string(root->val) + "->" + path);
        for(const auto& path : rightPaths) result.push_back(std::to_string(root->val) + "->" + path);

        if(result.size() == 0) result.push_back(std::to_string(root->val));
        return result;
    }
public:
    /**
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode * root) {
        const vector<string>& result = getPaths(root);

        return result;
    }

};

//Traversal
class Solution {
private:
    void helper(TreeNode * root, const std::string& path, std::vector<std::string>& result) {
        if(root == nullptr) return;

        if(root->left == nullptr && root->right == nullptr) {
            result.push_back(path);
            return;
        }

        if(root->left != nullptr) helper(root->left, path + "->" + std::to_string(root->left->val), result);
        if(root->right != nullptr) helper(root->right, path + "->" + std::to_string(root->right->val), result);
    }
public:
    /**
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode * root) {
        std::vector<std::string> result;
        if(root == nullptr) return result;

        helper(root, std::to_string(root->val), result);

        return result;
    }

};

// Iterative traversal
class Solution {
public:
    /**
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode * root) {
        std::vector<std::string> result;
        if(root == nullptr) return result;

        std::stack<TreeNode*> nodeStack;
        std::stack<std::string> pathStack;
        nodeStack.push(root);
        pathStack.push("");
        while(!nodeStack.empty()) {
            auto path = pathStack.top();
            pathStack.pop();
            auto node = nodeStack.top();
            nodeStack.pop();
            path += std::to_string(node->val);
            if(node->left == nullptr && node->right == nullptr) {
                result.push_back(path);
                continue;
            }
            path += "->";
            if(node->left != nullptr) {
                nodeStack.push(node->left);
                pathStack.push(path);
            }
            if(node->right != nullptr) {
                nodeStack.push(node->right);
                pathStack.push(path);
            }
        }

        return result;
    }

};