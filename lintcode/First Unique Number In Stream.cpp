class Solution {
private:
    struct Node {
        int m_val;
        Node * m_prev;
        Node * m_next;
        Node() : m_val(-1), m_prev(nullptr), m_next(nullptr) {}
        Node(int val) : m_val(val), m_prev(nullptr), m_next(nullptr) {}
    };
    std::unordered_map<int, Node*> m_uniqueNumIndex;
    std::unordered_set<int> m_existingNums;
    Node * m_dummy = new Node();
    Node * m_tail = m_dummy;
    
    void removeNode(Node * node) {
        //std::cout << "Removing node " << node->m_val << "\n";
        if(node == nullptr) return;
        if(node == m_tail) m_tail = node->m_prev;
        if(node->m_prev != nullptr) node->m_prev->m_next = node->m_next;
        if(node->m_next != nullptr) node->m_next->m_prev = node->m_prev;
    }
    
    int getFirstUnique(){
        if(m_uniqueNumIndex.size() == 0) return -1;
        if(m_dummy->m_next == nullptr) return -1;
        return m_dummy->m_next->m_val;
    }
public:
    /**
     * @param nums: a continuous stream of numbers
     * @param number: a number
     * @return: returns the first unique number
     */
    int firstUniqueNumber(vector<int> &nums, int number) {
        for(auto num : nums) {
            if(m_existingNums.count(num)) {
                //std::cout << num << " already exists\n";
                if(m_uniqueNumIndex.count(num)) {
                    //std::cout << "removing existing " << num << " from unique cache\n";
                    removeNode(m_uniqueNumIndex[num]);
                    m_uniqueNumIndex.erase(num);
                }
            } else {
                //std::cout << "Inserting " << num << "\n";
                m_existingNums.insert(num);
                m_uniqueNumIndex[num] = new Node(num);
                m_tail->m_next = m_uniqueNumIndex[num];
                m_uniqueNumIndex[num]->m_prev = m_tail;
                m_tail = m_tail->m_next;
            }
            if(num == number) {
                return getFirstUnique();
            }
        }
        return -1;
    }
};