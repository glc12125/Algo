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
    void getLeafs(TreeNode * root, int& sum) {
        if(root == nullptr) {
            return;
        }

        if(root->left == nullptr && root->right == nullptr) {
            sum += root->val;
            return;
        }
        getLeafs(root->left, sum);
        getLeafs(root->right, sum);
    }
public:
    /**
     * @param root:
     * @return: the sum of leafnode
     */
    int sumLeafNodeTraversal(TreeNode * root) {

        int sum = 0;
        getLeafs(root, sum);
        return sum;
    }


    int sumLeafNode(TreeNode * root) {

        int sum = 0;
        TreeNode* cur = nullptr;
        while(root != nullptr) {
            if(root->left != nullptr) {
                cur = root->left;
                while(cur->right != nullptr && cur->right != root) {
                    cur = cur->right;
                }

                if(cur->right == root) {
                    cur->right = nullptr;
                    if(cur->left == nullptr) {
                        sum += cur->val;
                    }
                    root = root->right;
                } else {
                    cur->right = root;
                    root = root->left;
                }
            } else {
                if(root->right == nullptr) {
                    sum += root->val;
                }
               root = root->right;
            }
        }
        return sum;
    }
};
