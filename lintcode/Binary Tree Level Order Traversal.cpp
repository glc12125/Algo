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
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        std::vector<std::vector<int> > result;
        if(root == nullptr) return result;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int qSize = q.size();
            std::vector<int> levelNodes;
            while(qSize > 0) {
                auto curr = q.front();
                q.pop();
                levelNodes.push_back(curr->val);
                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right != nullptr) q.push(curr->right);
                --qSize;
            }
            if(levelNodes.size() > 0) result.push_back(levelNodes);
        }
        return result;
    }
};