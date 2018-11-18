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

// Reverse Twice
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

// Recursive
class Solution {
private:
    int addOne(ListNode * head) {
        if(head == nullptr) return 1;

        int carry = addOne(head->next);
        int sum = carry + head->val;
        head->val = sum % 10;
        return sum / 10;
    }
public:
    /**
     * @param head: the first Node
     * @return: the answer after plus one
     */
    ListNode * plusOne(ListNode * head) {
        int carry = addOne(head);
        if(carry == 1) {
            ListNode * newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        }

        return head;
    }
};

//Iterative using Stack
class Solution {

public:
    /**
     * @param head: the first Node
     * @return: the answer after plus one
     */
    ListNode * plusOne(ListNode * head) {
        stack<ListNode*> s;

        auto curr = head;
        while(curr != nullptr) {
            s.push(curr);
            curr = curr->next;
        }

        int carry = 1;
        while(!s.empty()){
            auto curr = s.top();
            int sum = curr->val + carry;
            curr->val = sum %10;
            carry = sum / 10;
            s.pop();
        }

        if(carry == 1) {
            ListNode * newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        }

        return head;
    }
};

// One pass
class Solution {

public:
    /**
     * @param head: the first Node
     * @return: the answer after plus one
     */
    ListNode * plusOne(ListNode * head) {
        if(head == nullptr) return nullptr;
        ListNode * slow = head;
        ListNode * fast = head;
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;

        // Loop until fast is the last node, and update slow to the last node
        // that is not 9
        while(fast->next != nullptr) {
            if(fast->val == 9) {
                while(fast->next != nullptr && fast->val == 9) fast = fast->next;
            } else {
                slow = fast;
                fast = fast->next;
            }
        }

        if(fast->val == 9) {
            if(slow->val == 9) { // all 9 and slow is head
                ListNode * newHead = new ListNode(1);
                newHead->next = dummy->next;
                dummy->next = newHead;
            }

            int sum = slow->val + 1;
            slow->val = sum % 10;
            slow = slow->next;
            while(slow != nullptr) {
                slow->val = 0;
                slow = slow->next;
            }

            return dummy->next;
        } else {
            fast->val += 1;
            return dummy->next;
        }
    }
};