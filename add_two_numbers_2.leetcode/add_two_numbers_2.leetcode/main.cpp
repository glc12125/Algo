//
//  main.cpp
//  add_two_numbers_2.leetcode
//
//  Created by Liangchuan Gu on 14/12/2017.
//  Copyright © 2017 Liangchuan Gu. All rights reserved.
//

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    
};
 
class Solution {
public:
    void reverseList(ListNode** l) {
        if(*l == nullptr) return;
        ListNode * prev = nullptr;
        ListNode * next = (*l)->next;
        do {
            next = (*l)->next;
            (*l)->next = prev;
            prev = *l;
            *l = next;
        } while(next);
        *l = prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        reverseList(&l1);
        printList(l1);
        reverseList(&l2);
        printList(l2);
        ListNode * currentDigit = nullptr;
        ListNode * head = nullptr;
        int carryOver = 0;
        while(l1 || l2 || carryOver)
        {
            int currentSum = (l1?l1->val:0) + (l2?l2->val:0);
            currentDigit = new ListNode((carryOver + currentSum) % 10);
            carryOver = (carryOver + currentSum) / 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            // This check is useful for the last time check, where we do not want to
            currentDigit->next = head;
            head = currentDigit;
        }
        //printList(head);
        return head;
    }
    
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        std::vector<int> v1 = buildVector(l1);
        std::vector<int> v2 = buildVector(l2);
        
        auto s1 = v1.size();
        auto s2 = v2.size();
        int carry = 0;
        ListNode * head = nullptr;
        ListNode * p = nullptr;
        for(int i = s1 -1, j = s2 -1; (i >= 0 || j >= 0 || carry > 0); --i, --j)
        {
            int sum = carry;
            if(i >= 0) sum += v1[i];
            if(j >= 0) sum += v2[j];
            carry = sum /10;
            p = new ListNode(sum % 10);
            p->next = head;
            head = p;
        }
        
        return head;
    }
    
    std::vector<int> buildVector(ListNode * n)
    {
        std::vector<int> v;
        while(n)
        {
            v.push_back(n->val);
            n = n->next;
        }
        return v;
    }
    
    void printList(ListNode* node)
    {
        while(node)
        {
            std::cout << " " << node->val;
            node = node->next;
        }
        std::cout << "\n";
    }
    
    ListNode* addTwoNumbers2(ListNode * l1, ListNode *l2)
    {
        int countL1 = countNode(l1);
        int countL2 = countNode(l2);
        
        //keept the longer1 at l2
        if(countL1 > countL2 ) { ListNode* cur1= l2; l2 = l1; l1 = cur1;}
        //L1: 5--->6--->4
        //L2: 7--->2--->4--->3
        
        ListNode *pre = new ListNode(0); // store the most significant carr on
        
        int delta = std::abs(countL2 - countL1);
        while(l2 != nullptr)
        {
            ListNode *curNode = new ListNode(l2->val);
            l2 = l2->next;
            
            if(delta-- <= 0)
            {
                curNode->val += l1->val;
                l1 = l1->next;
            }
            
            curNode->next = pre;
            pre = curNode;
        }
        // 7<---7<---10<---7
        
        // reverse the result list and deal with carryOn
        int carryOn = 0;
        ListNode *head = pre;
        pre = nullptr;
        while(head != nullptr)
        {
            head->val += carryOn;
            carryOn = head->val / 10;
            head->val %= 10;
            
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        // 7--->8--->0--->7
        
        return pre->val == 0 ? pre->next : pre;
    }
    
    int countNode(ListNode *heard)
    {
        int count = 0;
        while(heard != nullptr)
        {
            count++;
            heard = heard->next;
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
//    ListNode *l1 = new ListNode(7);
//    l1->next = new ListNode(2);
//    l1->next->next = new ListNode(4);
//    l1->next->next->next = new ListNode(3);
//    ListNode * l2 = new ListNode(5);
//    l2->next = new ListNode(6);
//    l2->next->next = new ListNode(4);
    ListNode *l1 = new ListNode(5);
    ListNode *l2 = new ListNode(5);
    ListNode * result = s.addTwoNumbers2(l1, l2);
    s.printList(result);
    return 0;
}
