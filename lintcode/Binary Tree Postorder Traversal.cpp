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

    void postOrder(TreeNode* root) {
        if(root == nullptr) return;
        postOrder(root->left);
        postOrder(root->right);
        m_result.push_back(root->val);
    }
public:
    /**
     * @param root: A Tree
     * @return: Postorder in ArrayList which contains node values.
     */
    vector<int> postorderTraversal(TreeNode * root) {
        postOrder(root);
        return m_result;
    }
};

//Iterative
class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Postorder in ArrayList which contains node values.
     */
    vector<int> postorderTraversal(TreeNode * root) {
        std::vector<int> result;
        if(root == nullptr) result;

        std::stack<TreeNode *> myStack;

        TreeNode *current = root, *lastVisited = NULL;
        while (current != NULL || !myStack.empty()) {
            while (current != NULL) {
                myStack.push(current);
                current = current->left;
            }
            current = myStack.top();
            if (current->right == NULL || current->right == lastVisited) {
                myStack.pop();
                result.push_back(current->val);
                lastVisited = current;
                current = NULL;
            } else {
                current = current->right;
            }
        }

        return result;
    }
};