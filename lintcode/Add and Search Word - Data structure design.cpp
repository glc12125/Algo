class WordDictionary {
private:
    struct Node{
        char m_val;
        bool m_wordEnd;
        std::unordered_map<char, Node*> m_next;
        Node() : m_wordEnd(false) {}
        Node(char val) : m_val(val), m_wordEnd(false) {}
    };
    
    Node * m_head;
    
    bool dfsFind(Node * node, const std::string& word, int index) {
        if(index >= word.size()) return node->m_wordEnd;
        if(word[index] == '.') {
            if(node->m_next.size() == 0) return false;
            else {
                for(auto i : node->m_next) {
                    if(dfsFind(i.second, word, index + 1)) return true;
                }
                return false;
            }
        } else {
            if(node->m_next.count(word[index]) == 0) {
                return false; 
            } else {
                return dfsFind(node->m_next[word[index]], word, index + 1);
            }
        }
    }
public:
    WordDictionary(){
        m_head = new Node();
    }
    /*
     * @param word: Adds a word into the data structure.
     * @return: nothing
     */
    void addWord(string &word) {
        Node * node = m_head;
        for(int i = 0; i < word.size(); ++i) {
            if(node->m_next.count(word[i]) == 0) {
                node->m_next[word[i]] = new Node(word[i]);
            }
            node = node->m_next[word[i]];
        }
        node->m_wordEnd = true;
    }

    /*
     * @param word: A word could contain the dot character '.' to represent any one letter.
     * @return: if the word is in the data structure.
     */
    bool search(string &word) {
        if(word.size() == 0) return true;
        Node * node = m_head;

        return dfsFind(node, word, 0);
    }
};