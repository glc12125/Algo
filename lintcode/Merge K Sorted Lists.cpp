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

// Time O(nlogk)
class Solution {
private:
    struct NodeCompare {
        bool operator()(ListNode* n1, ListNode* n2) const {
            return n1->val > n2->val;
        }
    };
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, NodeCompare> q;
        for(auto node : lists) {
            if(node != NULL) q.push(node);
        }

        ListNode * dummy = new ListNode(-1);
        ListNode * tail = dummy;
        while(!q.empty()){
            ListNode * curr = q.top();
            q.pop();
            tail->next = curr;
            tail = curr;
            if(curr->next != NULL) q.push(curr->next);
        }

        return dummy->next;
    }
};

// Divide and Conquer
class Solution {
private:
    ListNode * mergeTwoLists(ListNode * f, ListNode * s) {
        ListNode * dummy = new ListNode(-1);
        ListNode * tail = dummy;

        while(f != NULL && s != NULL) {
            if(f->val < s->val)  {
                tail->next = f;
                tail = f;
                f = f->next;
            }
            else {
                tail->next = s;
                tail = s;
                s = s->next;
            }
        }

        if(f != NULL) {
            tail->next = f;
        }

        if(s != NULL) {
            tail->next = s;
        }

        return dummy->next;
    }

    ListNode * divideConquer(vector<ListNode *> &lists, int start, int end) {
        if(start == end) return lists[start];

        int mid = start + (end - start) / 2;

        auto firstList = divideConquer(lists, start, mid);
        auto secondList = divideConquer(lists, mid + 1, end);
        return mergeTwoLists(firstList, secondList);
    }
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty()) return NULL;
        return divideConquer(lists, 0, lists.size() - 1);
    }
};



