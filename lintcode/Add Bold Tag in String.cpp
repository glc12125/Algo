class Solution {
private:
class Trie {
private:
    struct Node{
        char m_val;
        bool m_wordEnd;
        Node* m_next[80] = {nullptr};
        Node() : m_wordEnd(false) {}
        Node(char val) : m_val(val), m_wordEnd(false) {}
    };

    int m_targetLen;
public:
    Node * m_head;

    Trie(int len) : m_targetLen(len) {
        m_head = new Node();
    }

    /*
     * @param word: a word
     * @return: nothing
     */
    void insert(const string& word) {
        Node * node = m_head;
        for(int i = 0; i < word.size(); ++i) {
            if(node->m_next[word[i]-'0'] == nullptr) {
                node->m_next[word[i]-'0'] = new Node(word[i]);
            }
            node = node->m_next[word[i] - '0'];
        }
        node->m_wordEnd = true;
    }

    /*
     * @param word: A string
     * @return: if the word is in the trie.
     */
    void search(Node * node, const string& target, int index, int& endIndex) {
        if(index >= m_targetLen) return;
        if(node->m_wordEnd) {
            endIndex = index;
        }

        if(node->m_next[target[index + 1] - '0'] == nullptr) {
            return;
        } else {
            search(node->m_next[target[index + 1] - '0'], target, index + 1, endIndex);
        }
    }

};

    vector<pair<int,int>> mergeIntervals(const vector<pair<int,int>>& boldPos) {
        vector<pair<int,int>> result;
        int len = boldPos.size();
        if(len == 0) return result;
        result.push_back(boldPos[0]);

        for(int i = 1; i < len; ++i) {
            auto& last = result.back();
            if(last.second < boldPos[i].first - 1) {
                result.push_back(boldPos[i]);
                continue;
            }
            last.second = std::max(last.second, boldPos[i].second);
        }
        return result;
    }
public:
    /**
     * @param s: a string
     * @param dict: a list of strings
     * @return: return a string
     */
    string addBoldTag(string &s, vector<string> &dict) {
        int lenS = s.size();
        if(lenS == 0) return "";

        Trie t(lenS);
        for(const auto& word : dict) {
            t.insert(word);
        }

        int startIndex = 0;
        int endIndex = 0;
        vector<pair<int,int>> boldPos;
        for(int i = 0; i < lenS; ++i) {
            if(t.m_head->m_next[s[i] - '0'] != nullptr) {
                startIndex = i;
                endIndex = -1;
                t.search(t.m_head->m_next[s[i] - '0'], s, i, endIndex);
                if(endIndex != -1) {
                    boldPos.push_back(pair<int, int>(startIndex, endIndex));
                }
            }
        }
        boldPos = mergeIntervals(boldPos);
        string result;
        int lastEnd = -1;
        for(const auto& interval : boldPos) {
            result += s.substr(lastEnd + 1, interval.first - lastEnd - 1);
            result += "<b>" + s.substr(interval.first, interval.second - interval.first + 1) + "</b>";
            lastEnd = interval.second;
        }
        if(lastEnd < lenS - 1) {
            result += s.substr(lastEnd + 1);
        }
        return result;
    }
};