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
 */


class Solution {
public:
    /*
     * @param node: a list node in the list
     * @param x: An integer
     * @return: the inserted new list node
     */
    ListNode * insert(ListNode * node, int x) {
        if (node == NULL) {
            node = new ListNode(x);
            node->next = node;
            return node;
        }

        ListNode* p = node;
        ListNode* prev = NULL;
        do {
            prev = p;
            p = p->next;
            if (x <= p->val && x >= prev->val) {
                break;
            }
            if ((prev->val > p->val) && (x < p->val || x > prev->val)) {
                break;
            }
        } while (p != node);

        ListNode* newNode = new ListNode(x);
        newNode->next = p;
        prev->next = newNode;
        return newNode;
    }
};