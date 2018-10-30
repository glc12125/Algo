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
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        int total = 0;
        for(auto node : hashTable) {
            if(node == nullptr) continue;
            while(node != nullptr) {
                ++total;
                node = node->next;
            }
        }
        if(total < hashTable.size() / 10) return hashTable;
        int newCapacity = hashTable.size() * 2;
        std::vector<ListNode*> rehashed(newCapacity, nullptr);
        for(auto node : hashTable) {
            if(node == nullptr) continue;
            std::stack<ListNode*> temp;
            while(node != nullptr) {
                temp.push(node);
                node = node->next;
            }
            while(!temp.empty()) {
                auto n = temp.top();
                int newIndex = (n->val + newCapacity ) % newCapacity;
                ListNode * newNode = new ListNode(n->val);
                ListNode * existing = rehashed[newIndex];
                newNode->next = existing;
                rehashed[newIndex] = newNode;
                temp.pop();
            }
        }
        return rehashed;
    }
};
