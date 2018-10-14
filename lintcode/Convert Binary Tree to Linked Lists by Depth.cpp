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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return a lists of linked list
     */
    vector<ListNode*> binaryTreeToLists(TreeNode* root) {
        if(root == nullptr) return std::vector<ListNode*>();
        
        std::queue<TreeNode*> q;
        q.push(root);
        std::vector<ListNode*> result;
        ListNode * guard = new ListNode(0);
        ListNode * prev = nullptr;
        while(!q.empty()) {
            int currentLen = q.size();
            guard->next = nullptr;
            prev = guard;
            while(currentLen > 0) {
                auto curr = q.front();
                q.pop();
                prev->next = new ListNode(curr->val);
                prev = prev->next;
                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right != nullptr) q.push(curr->right);
                --currentLen;
            }
            if(guard->next != nullptr) result.push_back(guard->next);
        }
        delete guard;
        return result;
    }
};