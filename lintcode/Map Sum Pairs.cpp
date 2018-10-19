class MapSum {
private:
    struct Node {
        std::unordered_map<std::string, int> m_counts;
        Node* m_next[26] = { nullptr };
        Node() = default;
    };

    Node * m_head;
public:
    /** Initialize your data structure here. */
    MapSum() {
        m_head = new Node();
    }

    void insert(string key, int val) {
        Node * curr = m_head;
        for(int i = 0; i < key.size(); ++i) {
            if(curr->m_next[key[i] - 'a'] == nullptr) {
                curr->m_next[key[i] - 'a'] = new Node();
            }
            curr = curr->m_next[key[i] - 'a'];
            curr->m_counts[key] = val;
        }
    }

    int sum(string prefix) {
        Node * curr = m_head;
        for(int i = 0; i < prefix.size(); ++i) {
            if(curr->m_next[prefix[i] - 'a'] == nullptr) {
                return 0;
            }
            curr = curr->m_next[prefix[i] - 'a'];
        }
        return std::accumulate(std::begin(curr->m_counts), std::end(curr->m_counts), 0,
                               [](const std::size_t previous, const std::pair<const std::string, int>& p)
                                    { return previous + p.second; });
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */

// Reduce space from O(m*n) to O(n)
class MapSum {
private:
    struct Node {
        int m_sum;
        Node* m_next[26] = { nullptr };
        Node() : m_sum(0) {}
    };

    Node * m_head;
    std::unordered_map<std::string, int> m_counts;
public:
    /** Initialize your data structure here. */
    MapSum() {
        m_head = new Node();
    }

    void insert(string key, int val) {
        int prevSum = (m_counts.count(key) > 0 ? m_counts[key] : 0);
        int diff = val - prevSum;

        m_counts[key] = val;
        Node * curr = m_head;
        for(int i = 0; i < key.size(); ++i) {
            if(curr->m_next[key[i] - 'a'] == nullptr) {
                curr->m_next[key[i] - 'a'] = new Node();
            }
            curr = curr->m_next[key[i] - 'a'];
            curr->m_sum += diff;
        }
    }

    int sum(string prefix) {
        Node * curr = m_head;
        for(int i = 0; i < prefix.size(); ++i) {
            if(curr->m_next[prefix[i] - 'a'] == nullptr) {
                return 0;
            }
            curr = curr->m_next[prefix[i] - 'a'];
        }
        return curr->m_sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */