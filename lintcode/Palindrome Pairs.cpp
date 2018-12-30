// Time O(N^2*W)
class Solution {
private:
    struct WordIndex{
        int m_index;
        string m_word;
        WordIndex() = default;
        WordIndex(int index, const string& word) : m_index(index), m_word(word) {}
    };

    bool isPalindrom(const string& word) {
        int l = 0;
        int r = word.size() - 1;
        while(l < r) {
            if(word[l] != word[r]) {
                return false;
            } else {
                ++l;
                --r;
            }
        }
        return true;
    }
public:
    /**
     * @param words: a list of unique words
     * @return: all pairs of distinct indices
     */
    vector<vector<int>> palindromePairs(vector<string> &words) {
        int len = words.size();
        vector<vector<int>> result;
        if(len == 0) return result;

        unordered_map<char, vector<WordIndex>> firstToWord;
        unordered_map<char, vector<WordIndex>> lastToWord;
        vector<int> emptyIndexes;
        vector<WordIndex> palindromeWords;

        for(int i = 0; i < len; ++i) {
            if(words[i].empty()) {
                emptyIndexes.push_back(i);
            } else {
                char first = words[i][0];
                char last = words[i].back();
                firstToWord[first].emplace_back(WordIndex(i, words[i]));
                lastToWord[last].emplace_back(WordIndex(i, words[i]));
                if(first == last && isPalindrom(words[i])) {
                    palindromeWords.emplace_back(WordIndex(i, words[i]));
                }
            }
        }

        // Empty string and palindrome word
        for(auto i : emptyIndexes) {
            for(const auto& word : palindromeWords) {
                result.push_back({i, word.m_index});
                result.push_back({word.m_index, i});
            }
        }

        for(auto& fIt : firstToWord) {
            for(auto& lIt : lastToWord) {
                if(fIt.first == lIt.first) {
                    //std::cout << "equal: " << fIt.first << "\n";
                    for(const auto& fWord : fIt.second) {
                        for(const auto& lWord : lIt.second) {
                            if(fWord.m_index != lWord.m_index && isPalindrom(fWord.m_word + lWord.m_word)) {
                                result.push_back({fWord.m_index, lWord.m_index});
                            }
                        }
                    }
                }
            }
        }

        return result;
    }
};


// Time O(N*W^3)
class Solution {
private:
    struct TrieNode{
        int m_index;
        TrieNode * m_children[26] = {nullptr};
        TrieNode(int index) : m_index(index) {}
    };

    bool isPalindrom(const string& word) {
        int l = 0;
        int r = word.size() - 1;
        while(l < r) {
            if(word[l] != word[r]) {
                return false;
            } else {
                ++l;
                --r;
            }
        }
        return true;
    }

    void insert(TrieNode* root, const string& word, int index) {
        TrieNode * current = root;
        for(auto c : word) {
            int pos = c - 'a';
            if(current->m_children[pos] == nullptr) {
                current->m_children[pos] = new TrieNode(-1);
            }
            current = current->m_children[pos];
        }
        current->m_index = index;
    }

    int search(TrieNode* root, const string& word) {
        TrieNode * current = root;
        for(auto c : word) {
            int pos = c - 'a';
            if(current->m_children[pos] == nullptr) {
                return - 1;
            }
            current = current->m_children[pos];
        }
        return current->m_index;
    }
public:
    /**
     * @param words: a list of unique words
     * @return: all pairs of distinct indices
     */
    vector<vector<int>> palindromePairs(vector<string> &words) {
        int len = words.size();
        vector<vector<int>> result;
        if(len == 0) return result;

        // Build Trie
        TrieNode * root = new TrieNode(-1);
        for(int i = 0; i < len; ++i) {
            insert(root, words[i], i);
        }

        for(int i = 0; i < len; ++i) {
            int wordLen = words[i].size();
            string reversedWord = words[i];
            reverse(reversedWord.begin(), reversedWord.end());
            for(int l = 0; l <= wordLen; ++l) {
                // check left substring of the reversed string
                // if it is palindrom and there is a match for the rest of the
                // substring in the Trie, we add
                if(isPalindrom(reversedWord.substr(0, l))) {
                    int index = search(root, reversedWord.substr(l));
                    if(index != -1 && index != i) {
                        result.push_back({i, index});
                    }
                }

                if(l != wordLen && isPalindrom(reversedWord.substr(l))) {
                    int index = search(root, reversedWord.substr(0, l));
                    if(index != -1 && index != i) {
                        result.push_back({index, i});
                    }
                }
            }
        }

        return result;
    }
};
