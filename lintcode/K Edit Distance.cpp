class Solution {
private:
    struct TrieNode {
        bool m_isWord;
        string m_word;
        TrieNode* m_children[26];
        TrieNode() : m_isWord(false) {
            for(int i = 0; i < 26; ++i) m_children[i] = nullptr;
        }
    };

    struct Trie{
        TrieNode * m_root;

        Trie() : m_root(new TrieNode()) {
        }

        void addNode(const string& word) {
            auto curr = m_root;
            for(auto c : word) {
                if(curr->m_children[c - 'a'] == nullptr) {
                    curr->m_children[c - 'a'] = new TrieNode();
                }
                curr = curr->m_children[c - 'a'];
            }
            curr->m_word = word;
            curr->m_isWord = true;
        }
    };

    void dpFind(TrieNode * node, const string& target, int k, vector<int>& dp, vector<string>& result) {
        int len = target.size();

        if(node->m_isWord && dp[len] <= k) result.push_back(node->m_word);

        vector<int> next(len + 1, 0);

        for(int i = 0; i < 26; ++i) {
            if(node->m_children[i] != nullptr) {
                next[0] = dp[0] + 1;
                for (int j = 1; j <= len; j++) {
                    if (target[j - 1] - 'a' == i) {
                        next[j] = std::min(dp[j - 1], std::min(next[j - 1] + 1, dp[j] + 1));
                    } else {
                        next[j] = std::min(dp[j - 1] + 1, std::min(next[j - 1] + 1, dp[j] + 1));
                    }
                }
                dpFind(node->m_children[i], target, k, next, result);
            }
        }
    }

public:
    /**
     * @param words: a set of stirngs
     * @param target: a target string
     * @param k: An integer
     * @return: output all the strings that meet the requirements
     */
    vector<string> kDistance(vector<string> &words, string &target, int k) {

        Trie trie;
        for(const auto& word : words) {
            trie.addNode(word);
        }

        int len = target.size();
        vector<int> dp(len + 1, 0);
        for(int i = 0; i <= len; ++i) dp[i] = i;
        vector<string> result;

        dpFind(trie.m_root, target, k, dp, result);

        return result;
    }
};