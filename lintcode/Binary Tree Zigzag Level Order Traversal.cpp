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
     * @return: A list of lists of integer include the zigzag level order traversal of its nodes' values.
     */
    vector<vector<int>> zigzagLevelOrder(TreeNode * root) {
        if(root == nullptr) return std::vector<std::vector<int> > ();
        
        std::queue<TreeNode*> q;
        q.push(root);
        std::vector<std::vector<int> > results;
        bool left = true;
        while(!q.empty()) {
            int currLen = q.size();
            std::vector<int> levelAnswer;
            while(currLen > 0) {
                auto curr = q.front();
                q.pop();
                levelAnswer.push_back(curr->val);
                if(curr->right) q.push(curr->right);
                if(curr->left) q.push(curr->left);
                --currLen;
            }
            if(left && levelAnswer.size() > 1) std::reverse(levelAnswer.begin(), levelAnswer.end());
            left = !left;
            results.push_back(levelAnswer);
        }
        return results;
    }
};