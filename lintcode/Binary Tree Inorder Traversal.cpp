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
    void inOrder(TreeNode* root) {
        if(root == nullptr) return;

        inOrder(root->left);
        m_result.push_back(root->val);
        inOrder(root->right);
    }
public:
    /**
     * @param root: A Tree
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode * root) {
        inOrder(root);
        return m_result;
    }
};

//Iterative
class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode * root) {
        std::vector<int> result;
        if(root == nullptr) return result;

        auto node = root;
        std::stack<TreeNode*> s;
        s.push(node);
        while(node != nullptr || !s.empty()) {
            if(node != nullptr) {
                s.push(node->left);
                node = node->left;
            } else {
                node = s.top();
                s.pop();
                if(node == nullptr) continue;
                result.push_back(node->val);
                node = node->right;
                s.push(node);
            }
        }

        return result;
    }
};

//Iterative approach 2
class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode * root) {
        std::vector<int> result;
        if(root == nullptr) return result;

        auto node = root;
        std::stack<TreeNode*> s;
        while(node != nullptr || !s.empty()) {
            while(node != nullptr) {
                s.push(node);
                node = node->left;
            }

            node = s.top();
            s.pop();
            result.push_back(node->val);
            node = node->right;
        }

        return result;
    }
};