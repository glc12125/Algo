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
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode * head) {
        if(head == nullptr) return false;

        auto fast = head->next;
        auto slow = head;
        while(fast != slow) {
            if(fast == nullptr || fast->next == nullptr) {
                return false;
            }

            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};