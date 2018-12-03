class LFUCache {
private:
struct LFUNode {
    int m_value;
    int m_key;
    int m_freq;
    LFUNode* m_next;
    LFUNode* m_prev;
    LFUNode(int key, int value) : m_key(key), m_value(value), m_freq(1), m_next(NULL), m_prev(NULL) {}
};

struct LinkedList {
    LFUNode* m_head;
    LFUNode* m_tail;

    LinkedList(): m_head(NULL), m_tail(NULL) {}

    void addHead(LFUNode* node) {
        node->m_next = m_head;
        node->m_prev = NULL;
        if (m_head != NULL) {
            m_head->m_prev = node;
        }
        m_head = node;
        if (m_tail == NULL) {
            m_tail = m_head;
        }
    }

    void removeNode(LFUNode* node){
        if (node->m_prev != NULL) {
            node->m_prev->m_next = node->m_next;
        } else {
            m_head = node->m_next;
        }

        if (node->m_next != NULL) {
            node->m_next->m_prev = node->m_prev;
        } else {
            m_tail = node->m_prev;
        }

    }
};

typedef std::unordered_map<int, LFUNode*> LFUContainer;
typedef std::unordered_map<int, LinkedList> FrequencyContainer;
typedef LFUContainer::iterator LfuIter;
typedef FrequencyContainer::iterator FreIter;

    int m_capacity;
    int m_lowestFreq;
    LFUContainer m_data;
    FrequencyContainer m_freqMap;
public:
    /*
    * @param capacity: An integer
    */LFUCache(int capacity) : m_capacity(capacity), m_lowestFreq(1) {
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        if (m_capacity == 0) return;
        LfuIter fItr = m_data.find(key);
        if (fItr == m_data.end()) {
            LFUNode* newNode = new LFUNode(key, value);
            if (m_data.size() == m_capacity) {
                FreIter iItr = m_freqMap.find(m_lowestFreq);
                LinkedList& list = iItr->second;
                m_data.erase(list.m_tail->m_key);
                list.removeNode(list.m_tail);
            }
            m_freqMap[1].addHead(newNode);
            m_data[key] = newNode;
            m_lowestFreq = 1;
        } else {
            LFUNode* node = fItr->second;
            node->m_value = value;
            FreIter fItr = m_freqMap.find(node->m_freq++);
            fItr->second.removeNode(node);
            if(fItr->second.m_head == NULL) {
                m_freqMap.erase(fItr);
            }
            LinkedList& list = m_freqMap[node->m_freq];
            if (m_freqMap.find(m_lowestFreq) == m_freqMap.end()) {
                m_lowestFreq = node->m_freq;
            }
            node->m_prev = NULL;
            node->m_next = NULL;
            list.addHead(node);

        }
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        if (m_capacity == 0) return -1;
        LfuIter itr = m_data.find(key);
        if(itr != m_data.end()) {
            LFUNode* node = itr->second;
            FreIter fItr = m_freqMap.find(node->m_freq++);
            fItr->second.removeNode(node);
            if (fItr->second.m_head == NULL) {
                m_freqMap.erase(fItr);
            }
            if (m_freqMap.find(m_lowestFreq) == m_freqMap.end()) {
                m_lowestFreq = node->m_freq;
            }
            m_freqMap[node->m_freq].addHead(node);

            return node->m_value;
        } else {
            return -1;
        }
    }
};