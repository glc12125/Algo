  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(0) {}
  };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == 0 || headB == 0) {
            return 0;
        }
        
        ListNode *aCur = new ListNode(headA->val);
        aCur->next = headA->next;
        int aLength = 1;
        while (aCur->next != 0) {
            ++aLength;
            aCur->next = aCur->next->next;
        }
        ListNode *bCur = new ListNode(headB->val);
        bCur->next = headB->next;
        int bLength = 1;
        while (bCur->next != 0) {
            ++bLength;
            bCur->next = bCur->next->next;
        }
        int diff = aLength - bLength;
        
        aCur->next = headA->next;
        aCur->val = headA->val;
        bCur->next = headB->next;
        bCur->val = headB->val;
        if (diff >= 0) {
            while (diff > 0) {
                aCur->val = aCur->next->val;
                aCur->next = aCur->next->next;
                --diff;
            }
        } else {
            while (diff < 0) {
                bCur->val = bCur->next->val;
                bCur->next = bCur->next->next;
                ++diff;
            }
        }
        
        if (aCur->val == bCur->val) {
            ListNode * toReturn = (aCur->val == headA->val ? headA : headB);
            delete aCur;
            delete bCur;
            return toReturn;
        }
        
        while (aCur->next != 0 && bCur->next != 0) {
            if (aCur->next->val == bCur->next->val) {
                delete aCur;
                delete bCur;
                return aCur->next;
            }
            aCur->val = aCur->next->val;
            aCur->next = aCur->next->next;
            bCur->val = bCur->next->val;
            bCur->next = bCur->next->next;
        }
        
        delete aCur;
        delete bCur;
        
        return 0;

    }
};
