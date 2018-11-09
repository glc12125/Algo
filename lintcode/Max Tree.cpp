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
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode * maxTree(vector<int> &A) {
        int len = A.size();
        if(len == 0) return nullptr;

        vector<TreeNode*> indexStack;
        for(int i = 0; i <= len; ++i) {
            int curr = (i == len ? INT_MAX : A[i]);
            TreeNode * newNode = new TreeNode(curr);
            while(!indexStack.empty() && curr >= indexStack[indexStack.size() - 1]->val) {
                newNode->left = indexStack.back();
                indexStack.pop_back();
            }
            if(!indexStack.empty()) {
                indexStack.back()->right = newNode;
            }
            indexStack.push_back(newNode);
        }
        return indexStack.back()->left;
    }
};

// With extra O(N) space using actual stack
class Solution {
public:
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode * maxTree(vector<int> &A) {
        int len = A.size();
        if(len == 0) return nullptr;

        stack<int> indexStack;
        unordered_map<int, TreeNode*> container;
        for(int i = 0; i <= len; ++i) {
            int curr = (i == len ? INT_MAX : A[i]);
            container[i] = new TreeNode(curr);
            int prev = -1;
            while(!indexStack.empty() && curr >= A[indexStack.top()]) {
                int smallerIndex = indexStack.top();
                if(prev != -1) {
                    container[smallerIndex]->right = container[prev];
                }
                indexStack.pop();
                prev = smallerIndex;
            }
            if(prev != -1) {
                container[i]->left = container[prev];
            }
            indexStack.push(i);
        }
        return container[len]->left;
    }
};