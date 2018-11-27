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
    void getLeftNodes(TreeNode* node, vector<int>& result) {
        if(node == nullptr || (node->left == nullptr && node->right == nullptr)) {
            return;
        }

        result.push_back(node->val);
        if(node->left != nullptr) {
            getLeftNodes(node->left, result);
        } else {
            getLeftNodes(node->right, result);
        }
    }

    void getRightNodes(TreeNode* node, vector<int>& result) {
        if(node == nullptr || (node->left == nullptr && node->right == nullptr)) {
            return;
        }

        if(node->right != nullptr) {
            getRightNodes(node->right, result);
        } else {
            getRightNodes(node->left, result);
        }
        result.push_back(node->val);
    }

    void getLeafNodes(TreeNode* node, vector<int>& result) {
        if(node == nullptr) {
            return;
        }
        if(node->left == nullptr && node->right == nullptr) {
            result.push_back(node->val);
            return;
        }

        getLeafNodes(node->left, result);
        getLeafNodes(node->right, result);
    }
public:
    /**
     * @param root: a TreeNode
     * @return: a list of integer
     */
    vector<int> boundaryOfBinaryTree(TreeNode * root) {
        if(root == nullptr) return {};

        vector<int> result(1, root->val);
        getLeftNodes(root->left, result);
        getLeafNodes(root, result);
        getRightNodes(root->right, result);

        return result;
    }
};