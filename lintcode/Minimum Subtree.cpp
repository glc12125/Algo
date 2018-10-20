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

// Divide & conquer and traversal
class Solution {
private:
    int m_minimumSum = INT_MAX;
    TreeNode * m_result = nullptr;

    int findMinimum(TreeNode * node) {
        if(node == nullptr) return 0;

        auto leftSum = findMinimum(node->left);
        auto rightSum = findMinimum(node->right);

        if(leftSum + rightSum + node->val <= m_minimumSum){
            m_minimumSum = leftSum + rightSum + node->val;
            m_result = node;
        }

        return leftSum + rightSum + node->val;
    }
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the minimum subtree
     */
    TreeNode * findSubtree(TreeNode * root) {
        findMinimum(root);
        return m_result;
    }
};

// Divide and conquer
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
    struct ResultType {
        int m_sum;
        int m_minimum;
        TreeNode * m_subTreeNode;
        ResultType () : m_sum(0), m_minimum(INT_MAX), m_subTreeNode(nullptr)  {}
        ResultType (int sum, int minimum, TreeNode * node) : m_sum(sum), m_minimum(minimum), m_subTreeNode(node)  {}
    };

    ResultType findMinimum(TreeNode * node) {
        if(node == nullptr) return ResultType(0, INT_MAX, nullptr);

        const auto& resultLeft = findMinimum(node->left);
        const auto& resultRight = findMinimum(node->right);

        int sum = resultLeft.m_sum + resultRight.m_sum + node->val;
        if(resultLeft.m_minimum == std::min(sum, std::min(resultLeft.m_minimum, resultRight.m_minimum))) {
            return ResultType(sum, resultLeft.m_minimum, resultLeft.m_subTreeNode);
        }

        if(resultRight.m_minimum == std::min(sum, std::min(resultLeft.m_minimum, resultRight.m_minimum))) {
            return ResultType(sum, resultRight.m_minimum, resultRight.m_subTreeNode);
        }

        return ResultType(sum, sum, node);
    }
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the minimum subtree
     */
    TreeNode * findSubtree(TreeNode * root) {
        auto result = findMinimum(root);
        return result.m_subTreeNode;
    }
};