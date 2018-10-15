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
     * @param root: A tree
     * @return: buttom-up level order a list of lists of integer
     */
    vector<vector<int>> levelOrderBottom(TreeNode * root) {
        if(root == nullptr) return std::vector<std::vector<int> > ();

        std::queue<TreeNode*> q;
        q.push(root);
        std::vector<std::vector<int> > results;
        while(!q.empty()) {
            int currLen = q.size();
            std::vector<int> levelAnswer;
            while(currLen > 0) {
                auto curr = q.front();
                q.pop();
                levelAnswer.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                --currLen;
            }
            results.push_back(levelAnswer);
        }
        std::reverse(results.begin(), results.end());
        return results;
    }
};