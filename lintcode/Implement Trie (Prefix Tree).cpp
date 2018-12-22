class Trie {
private:
    struct Node{
        char m_val;
        bool m_wordEnd;
        Node* m_next[26] = {nullptr};
        Node() : m_wordEnd(false) {}
        Node(char val) : m_val(val), m_wordEnd(false) {}
    };

    Node * m_head;
public:
    Trie() {
        m_head = new Node();
    }

    /*
     * @param word: a word
     * @return: nothing
     */
    void insert(string& word) {
        Node * node = m_head;
        for(int i = 0; i < word.size(); ++i) {
            if(node->m_next[word[i]-'a'] == nullptr) {
                node->m_next[word[i]-'a'] = new Node(word[i]);
            }
            node = node->m_next[word[i] - 'a'];
        }
        node->m_wordEnd = true;
    }

    /*
     * @param word: A string
     * @return: if the word is in the trie.
     */
    bool search(string& word) {
        if(word.size() == 0) return true;
        Node * node = m_head;

        for(int i = 0; i < word.size(); ++i) {
            if(node->m_next[word[i] - 'a'] == nullptr) {
                return false;
            }
            node = node->m_next[word[i] - 'a'];
        }
        return node->m_wordEnd;
    }

    /*
     * @param prefix: A string
     * @return: if there is any word in the trie that starts with the given prefix.
     */
    bool startsWith(string& prefix) {
        if(prefix.size() == 0) return true;
        Node * node = m_head;
        for(int i = 0; i < prefix.size(); ++i) {
            if(node->m_next[prefix[i] - 'a'] == nullptr) {
                return false;
            }
            node = node->m_next[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */