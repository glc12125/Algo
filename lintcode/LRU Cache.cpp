class LRUCache {
private:
    struct Node {
        int m_key;
        int m_value;
        Node * m_prev;
        Node * m_next;
        Node(int key, int value) :
            m_key(key), m_value(value),
            m_prev(nullptr), m_next(nullptr) {
        }
    };

    Node * m_recent;
    Node * m_stale;
    int m_totalSize;
    std::unordered_map<int, Node*> m_cache;

    void removeNode(Node* node) {
        Node * prev = node->m_prev;
        Node * next = node->m_next;
        if(prev != nullptr) {
            prev->m_next = next;
        } else {
            m_recent = next;
        }

        if(next != nullptr) {
            next->m_prev = prev;
        } else {
            m_stale = prev;
        }
    }

    void makeRecent(Node* node) {
        if(m_recent == nullptr) {
            m_stale = node;
            m_recent = node;
            //std::cout << "current recent: " << m_recent->m_key << "\n";
            return;
        }

        node->m_next = m_recent;
        m_recent->m_prev = node;
        node->m_prev = nullptr;
        m_recent = node;
        if(m_stale == nullptr) m_stale = m_recent;
        //std::cout << "current recent: " << m_recent->m_key << "\n";
    }

public:
    /*
    * @param capacity: An integer
    */LRUCache(int capacity) {
        m_recent = nullptr;
        m_stale = nullptr;
        m_totalSize = capacity;
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        if(m_cache.count(key) > 0) {
            removeNode(m_cache[key]);
            makeRecent(m_cache[key]);
            return m_cache[key]->m_value;
        }
        return -1;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        //std::cout << "calling set: key " << key << ", value " << value << "\n";
        if(m_cache.count(key) > 0) {
            removeNode(m_cache[key]);
            makeRecent(m_cache[key]);
            m_cache[key]->m_value = value;
        } else {
            if(m_cache.size() == m_totalSize) {
                //std::cout << "trying to set: " << key << "\n";
                m_cache.erase(m_stale->m_key);
                removeNode(m_stale);
            }
            Node * newNode = new Node(key, value);
            m_cache[key] = newNode;
            makeRecent(newNode);
        }
    }
};