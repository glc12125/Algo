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
        bool m_isValid;
        TreeNode* m_min;
        TreeNode* m_max;
        ResultType(bool isValid) : m_isValid(isValid), m_min(nullptr), m_max(nullptr) {}
    };

    ResultType getState(TreeNode * root) {
        if(root == nullptr) {
            return ResultType(true);
        }

        auto leftResult = getState(root->left);
        auto rightResult = getState(root->right);

        if(!leftResult.m_isValid) return ResultType(false);
        if(!rightResult.m_isValid) return ResultType(false);

        if(leftResult.m_max != nullptr && leftResult.m_max->val >= root->val) return ResultType(false);
        if(rightResult.m_min != nullptr && rightResult.m_min->val <= root->val) return ResultType(false);

        ResultType result(true);
        result.m_min = leftResult.m_min != nullptr ? leftResult.m_min : root;
        result.m_max = rightResult.m_max != nullptr ? rightResult.m_max : root;
        return result;
    }
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        auto result = getState(root);
        return result.m_isValid;
    }
};