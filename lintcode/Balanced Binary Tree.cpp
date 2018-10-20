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
    struct ResultType{
        bool m_isBalanced;
        int m_height;
        ResultType(bool isBalanced, int height) : m_isBalanced(isBalanced), m_height(height) {}
    };

    ResultType getBalanced(TreeNode * root) {
        if(root == nullptr) {
            return ResultType(true, 0);
        }

        auto resultLeft = getBalanced(root->left);
        auto resultRight = getBalanced(root->right);

        bool isBalanced = (resultLeft.m_isBalanced && resultRight.m_isBalanced && std::abs(resultLeft.m_height - resultRight.m_height) < 2);
        return ResultType(isBalanced, std::max(resultLeft.m_height, resultRight.m_height) + 1);
    }
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode * root) {
        auto result = getBalanced(root);
        return result.m_isBalanced;
    }
};