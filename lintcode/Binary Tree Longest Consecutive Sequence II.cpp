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
        int m_maxLen;
        int m_maxUp;
        int m_maxDown;
        ResultType(int len, int up, int down) : m_maxLen(len), m_maxUp(up), m_maxDown(down) {}
    };

    ResultType divideAndConquer(TreeNode * root) {
        if(root == nullptr) {
            return ResultType(0, 0, 0);
        }

        auto leftResult = divideAndConquer(root->left);
        auto rightResult = divideAndConquer(root->right);

        int down = 0;
        int up = 0;
        if(root->left != nullptr && root->left->val + 1 == root->val) {
            down = std::max(down, leftResult.m_maxDown + 1);
        }
        if(root->left != nullptr && root->left->val - 1 == root->val) {
            up = std::max(up, leftResult.m_maxUp + 1);
        }
        if(root->right != nullptr && root->right->val + 1 == root->val) {
            down = std::max(down, rightResult.m_maxDown + 1);
        }
        if(root->right != nullptr && root->right->val - 1 == root->val) {
            up = std::max(up, rightResult.m_maxUp + 1);
        }

        int len = down + 1 + up;
        len = std::max(len, std::max(leftResult.m_maxLen, rightResult.m_maxLen));

        return ResultType(len, up, down);
    }
public:
    /**
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    int longestConsecutive2(TreeNode * root) {
        return divideAndConquer(root).m_maxLen;
    }
};