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
    void helper(TreeNode * curr, TreeNode * prev, int count, int& maxConseqNum) {
        if (curr == nullptr) return;
        if(prev != nullptr && curr->val == prev->val + 1) {
            ++count;
            maxConseqNum = std::max(maxConseqNum, count);
        } else count = 1;
        helper(curr->left, curr, count, maxConseqNum);
        helper(curr->right, curr, count, maxConseqNum);
    }
public:
    /**
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    int longestConsecutive(TreeNode * root) {
        int maxConseqNum = 1;
        helper(root, nullptr, 0, maxConseqNum);
        return maxConseqNum;
    }
};