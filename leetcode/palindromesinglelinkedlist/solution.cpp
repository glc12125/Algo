#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
    static void reverse(ListNode **head_ref)
    {
        ListNode *prev   = NULL;
        ListNode *current = *head_ref;
        ListNode *next = NULL;
        while (current != NULL) {
            next  = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        *head_ref = prev;

    }

public:
    bool isPalindrome(ListNode *head)
    {

        if (head == NULL || head->next == NULL) {
            return true;
        }

        ListNode *one = head;
        ListNode *two = head;
        bool isOdd = false;
        while (two != NULL) {
            if (two->next == NULL) {
                isOdd = true;
                break;
            }
            one = one->next;
            two = two->next->next;
        }

        two = head;
        if (isOdd) {
            one = one->next;
        }

        reverse(&one);
        while ( one != NULL) {
            if (one->val != two->val) {
                cout << one->val << ", " << two->val << endl;
                return false;
            }
            one = one->next;
            two = two->next;
        }

        return true;
    }
};

int main()
{
    ListNode head(1);
    ListNode one(2);
    ListNode two(2);
    ListNode three(1);
    head.next = &one;
    one.next = &two;
    two.next = &three;

    Solution solution;
    bool result = solution.isPalindrome(&head);

    cout << "result: " << result << endl;
}
