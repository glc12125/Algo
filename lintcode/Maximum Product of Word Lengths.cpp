// Time O(M*N^2), where M is the average word length, N is the number of words, space O(M*N)
class Solution {
public:
    /**
     * @param words: a string array
     * @return: the maximum product
     */
    int maxProduct(vector<string> &words) {
        int len = words.size();
        if(len == 0) return 0;
        unordered_map<int, unordered_set<char>> wordChars;
        for(int i = 0; i < len; ++i) {
            wordChars[i].insert(words[i].begin(), words[i].end());
        }

        size_t maxProduct = 0;
        for(int i = 0; i < len; ++i) {
            for(int j = i + 1; j < len; ++j) {
                bool isCandidate = true;
                for(char ci : wordChars[i]) {
                    if(wordChars[j].count(ci) > 0) {
                        isCandidate = false;
                        break;
                    }
                }
                if(isCandidate) maxProduct = std::max(maxProduct, words[i].size() * words[j].size());
            }
        }

        return maxProduct;
    }
};

// Time O(N^2), space O(N)
class Solution {
public:
    /**
     * @param words: a string array
     * @return: the maximum product
     */
    int maxProduct(vector<string> &words) {
        int len = words.size();
        if(len == 0) return 0;
        vector<int> counters(len, 0);

        for(int i = 0; i < len; ++i) {
            int count = 0;
            for(auto c : words[i]) {
                count |= (1<<(c-'a'));
            }
            counters[i] = count;
        }

        size_t maxProduct = 0;
        for(int i = 0; i < len; ++i) {
            for(int j = i + 1; j < len; ++j) {
                if(counters[i]&counters[j]) continue;
                maxProduct = std::max(maxProduct, words[i].size() * words[j].size());
            }
        }

        return maxProduct;
    }
};