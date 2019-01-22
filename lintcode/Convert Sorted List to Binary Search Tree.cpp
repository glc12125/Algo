/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
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
    /*
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        int size = getListSize(head);
        return convertHelper(head, size);
    }

    int getListSize(ListNode *head) {
        int size = 0;
        while (head != NULL) {
            head = head->next;
            size++;
        }
        return size;
    }

    TreeNode *convertHelper(ListNode *&head, int size) {
        if (size == 0) {
            return NULL;
        }

        TreeNode *root = new TreeNode(0);
        root->left = convertHelper(head, size / 2);
        root->val = head->val; head = head->next;
        root->right = convertHelper(head, size - size / 2 - 1);
        return root;
    }
};