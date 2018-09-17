
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, 
                                       TreeNode* p, 
                                       TreeNode* q) {
            if (root == NULL) {
                return NULL;
            }
            if (p->val <= root->val &&
                q->val >= root->val) {
                return root;
            }
            TreeNode * result;
            if (root->val > p->val &&
                root->val > q->val) {
                result = lowestCommonAncestor(root->left, p, q);
            }

            if (root->val < p->val &&
                    root->val < q->val) {
                result = lowestCommonAncestor(root->right, p, q);
            }
            return result;            
        }
};

