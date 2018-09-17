#include <stack>
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 
struct TreeNodeWithState {
     TreeNode * node;
     int unvisitedChildrenNum;
     TreeNodeWithState(TreeNode* n): node(n), unvisitedChildrenNum(0){};
 };
 
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }
        int currentSum = 0;
        std::stack<TreeNode*> q;
        std::stack<TreeNodeWithState> parentNodes;
        q.push(root);
        while (!q.empty()) {
            TreeNode * node = q.top();
            q.pop();
            
            currentSum += node->val;
            if (currentSum == sum) {
                if (node->left == NULL && node->right == NULL) {
                    return true;
                }
            } 

            if (node->left == NULL && node->right == NULL) {
                if (parentNodes.empty()) {
                    continue;
                }
                TreeNodeWithState& parentNode = parentNodes.top();
                --(parentNode.unvisitedChildrenNum);
                currentSum -= node->val;
                if (parentNode.unvisitedChildrenNum == 0 && parentNode.node != root) {
                    currentSum -= parentNode.node->val;
                    parentNodes.pop();
                    // For root that only has one child, we should not pop it.
                    while (parentNodes.top().node != root && parentNodes.top().unvisitedChildrenNum == 1) {
                        currentSum -= parentNodes.top().node->val;
                        parentNodes.pop();
                    }

                    TreeNodeWithState& tmp = parentNodes.top();
                    --(tmp.unvisitedChildrenNum);

                }
                continue;
            }
            if (node->left != NULL || node->right != NULL) {
                TreeNodeWithState n(node);

                if (node->left != NULL) {
                    q.push(node->left);
                    ++(n.unvisitedChildrenNum);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                    ++(n.unvisitedChildrenNum);
                }
                parentNodes.push(n);
            }
                
        }
        
       return false; 
    }
};
