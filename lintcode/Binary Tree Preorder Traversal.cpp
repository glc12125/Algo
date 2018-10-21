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
    std::vector<int> m_result;

    void preOrder(TreeNode * root) {
        if(root == nullptr) return;

        m_result.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
public:
    /**
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
    vector<int> preorderTraversal(TreeNode * root) {
        preOrder(root);
        return m_result;
    }
};

// Iterative
class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
    vector<int> preorderTraversal(TreeNode * root) {
        std::vector<int> result;
        if(root == nullptr) return result;

        std::stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            auto node = s.top();
            s.pop();
            result.push_back(node->val);
            if(node->right != nullptr) s.push(node->right);
            if(node->left != nullptr) s.push(node->left);
        }

        return result;
    }
};