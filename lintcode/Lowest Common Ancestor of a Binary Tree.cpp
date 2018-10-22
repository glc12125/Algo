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
    TreeNode * findLca(TreeNode * root, TreeNode * A, TreeNode * B) {
        if(root == nullptr || root == A || root == B) return root;

        auto left = findLca(root->left, A, B);
        auto right = findLca(root->right, A, B);

        if(left != nullptr && right != nullptr) return root;
        if(left != nullptr) {
            return left;
        }
        if(right != nullptr) {
            return right;
        }
        return nullptr;
    }
public:
    /*
     * @param root: The root of the binary search tree.
     * @param A: A TreeNode in a Binary.
     * @param B: A TreeNode in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
        if(A == B) return A;
        return findLca(root, A, B);
    }
};