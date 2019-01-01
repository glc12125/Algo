class Solution {
private:
    struct TrieNode {
        vector<int> m_indexes;
        TrieNode * m_children[26] = {nullptr};
    };

    void insert(TrieNode * root, const string& word, int index) {
        auto current = root;
        for(auto c : word) {
            int pos = c - 'a';
            if(current->m_children[pos] == nullptr) {
                current->m_children[pos] = new TrieNode();
            }
            current = current->m_children[pos];
            current->m_indexes.push_back(index);
        }
    }

    TrieNode * m_root;

    void dfs(const vector<string>& words, int index, int wordSize, vector<string>& candidate, vector<vector<string>>& answer) {
        int len = words.size();
        if(index == wordSize) {
            answer.push_back(candidate);
            return;
        }

        string prefixSoFar;
        for(int i = 0; i < index; ++i) {
            prefixSoFar += candidate[i][index];
        }

        auto currentNode = m_root;
        for(auto c : prefixSoFar) {
            int pos = c - 'a';
            if(currentNode->m_children[pos] == nullptr) {
                return;
            }
            currentNode = currentNode->m_children[pos];
        }

        const auto& nextIndexes = currentNode->m_indexes;

        for(auto nextIndex : nextIndexes) {
            candidate[index] = words[nextIndex];
            dfs(words, index + 1, wordSize, candidate, answer);
        }
    }

public:
    /*
     * @param words: a set of words without duplicates
     * @return: all word squares
     */
    vector<vector<string>> wordSquares(vector<string> &words) {
        vector<vector<string>> answer;
        int wordCount = words.size();
        if(wordCount == 0) {return answer;}
        int wordSize = words[0].size();

        m_root = new TrieNode();
        for(int i = 0; i < wordCount; ++i) {
            insert(m_root, words[i], i);
        }
        vector<string> candidate(wordSize);

        for(const auto& word : words) {
            candidate[0] = word;
            dfs(words, 1, wordSize, candidate, answer);
        }
        return answer;
    }
};

