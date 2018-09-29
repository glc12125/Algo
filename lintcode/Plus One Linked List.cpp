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
private:
    ListNode * reverseLL(ListNode * head) {
        ListNode * curr = head;
        ListNode * prev = NULL;
        while(curr != NULL) {
            auto temp = curr;
            curr = curr->next;
            temp->next = prev;
            prev = temp;
        }
        return prev;
    }
public:
    /**
     * @param head: the first Node
     * @return: the answer after plus one
     */
    ListNode * plusOne(ListNode * head) {
        auto revHead = reverseLL(head);
        ListNode * curr = revHead;
        ListNode * last = NULL;
        int carry = 1;
        while(curr != NULL) {
            int sum = carry + curr->val;
            curr->val = sum%10;
            carry = sum/10;
            last = curr;
            curr = curr->next;
        }
        if(carry != 0) {
            last->next = new ListNode(carry);
        }
        return reverseLL(revHead);
    }
};