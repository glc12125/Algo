/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: the head of linked list.
     * @return: a middle node of the linked list
     */
    ListNode * middleNode(ListNode * head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode * curr = head;
        ListNode * middle = head;

        while(curr->next != nullptr && curr->next->next != nullptr) {
            curr = curr->next->next;
            middle = middle->next;
        }

        return middle;
    }
};