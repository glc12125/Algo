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
     * @param root: a root of integer
     * @return: return a integer
     */
    vector<int> findMode(TreeNode * root) {
        vector<int> result;
        if(root == nullptr) return result;
        std::stack<TreeNode *> s;
        TreeNode * curr = root;
        int prevVal = -1;
        int counter = 1;
        int maxCounter = 1;

        while (curr != nullptr || s.empty() == false) {
            if (curr !=  nullptr)
            {
                s.push(curr);
                curr = curr->left;
            } else {
                curr = s.top();
                s.pop();
                if(prevVal != -1) {
                    if(curr->val == prevVal) {
                        ++counter;
                    } else{
                        counter = 1;
                    }
                    if(maxCounter < counter) {
                        maxCounter = counter;
                        result.clear();
                        result.push_back(prevVal);
                    } else if (maxCounter == counter){
                        result.push_back(prevVal);
                    }
                }
                prevVal = curr->val;
                curr = curr->right;
            }
        }

        if (maxCounter == 1){
            result.push_back(prevVal);
        }
    	return result;

    }
};