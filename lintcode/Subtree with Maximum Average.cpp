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
        float m_sum;
        int m_count;
        ResultType() : m_sum(0), m_count(0) {}
        ResultType(int sum, int count) : m_sum(sum), m_count(count) {}
    };

    ResultType m_result;
    TreeNode * m_resultNode = nullptr;

    ResultType divideNConquer(TreeNode * root) {
        if(root == nullptr) return ResultType();

        auto leftResult = divideNConquer(root->left);
        auto rightResult = divideNConquer(root->right);

        ResultType result(leftResult.m_sum + root->val + rightResult.m_sum , leftResult.m_count + 1 + rightResult.m_count);

        if(m_resultNode == nullptr || m_result.m_sum / m_result.m_count < result.m_sum / result.m_count) {
            m_resultNode = root;
            m_result = result;
        }
        return result;
    }

public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the maximum average of subtree
     */
    TreeNode * findSubtree2(TreeNode * root) {
        divideNConquer(root);
        return m_resultNode;
    }
};