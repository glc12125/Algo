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
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        TreeNode * curr = root;
        std::stack<TreeNode*> s;
        
        int rank = 1;
        while(curr != nullptr || !s.empty()) {
            if(curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            } else {
                curr = s.top();
                s.pop();
                if(rank++ == k) return curr->val;
                curr = curr->right;
            }
        }
    }
};

//Solution2, recursive

class Solution {
private:
    void inOrder(TreeNode* node, int k, int& rank, int&result){
        if(node == nullptr) return;
        inOrder(node->left, k, rank, result);
        if(rank++ == k) {
            result = node->val;
            return;
        }
        inOrder(node->right, k, rank, result);
    }
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        int rank = 1;
        int result = 0;
        inOrder(root, k, rank, result);
        return result;
    }
};