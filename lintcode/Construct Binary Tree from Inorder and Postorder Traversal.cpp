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
    using Itr = std::vector<int>::iterator;
    TreeNode* buildTreeHelper(Itr iBegin, Itr iEnd, Itr pBegin, Itr pEnd) {
        if(iBegin == iEnd) return nullptr;
        auto rootVal = *(pEnd-1);
        auto iRootIter = std::find(iBegin, iEnd, rootVal);
        TreeNode * root = new TreeNode(rootVal);
        root->left = buildTreeHelper(iBegin, iRootIter, pBegin, pBegin + (iRootIter - iBegin));
        root->right = buildTreeHelper(iRootIter + 1, iEnd, pBegin + (iRootIter - iBegin), pEnd-1);
        return root;
    }
public:
    /**
     * @param inorder: A list of integers that inorder traversal of a tree
     * @param postorder: A list of integers that postorder traversal of a tree
     * @return: Root of a tree
     */
    TreeNode * buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() == 0) return nullptr;
        return buildTreeHelper(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
};