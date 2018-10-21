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
    using Iter = std::vector<int>::iterator;
    TreeNode * buildTreeHelper(Iter pBegin, Iter pEnd, Iter iBegin, Iter iEnd) {
        if(iBegin == iEnd) return nullptr;
        int rootVal = *pBegin;
        auto rootIter = std::find(iBegin, iEnd, rootVal);
        
        TreeNode * root = new TreeNode(rootVal);
        root->left = buildTreeHelper(pBegin + 1, pBegin + (rootIter - iBegin + 1), iBegin, rootIter);
        root->right = buildTreeHelper(pBegin + (rootIter - iBegin + 1), pEnd, rootIter+1, iEnd);
        return root;
    }
public:
    /**
     * @param inorder: A list of integers that inorder traversal of a tree
     * @param postorder: A list of integers that postorder traversal of a tree
     * @return: Root of a tree
     */
    TreeNode * buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(inorder.size() == 0) return nullptr;
        return buildTreeHelper(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};