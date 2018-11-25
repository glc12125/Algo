class Solution {
public:
    /**
     * @param S: a string
     * @param words: a dictionary of words
     * @return: the number of words[i] that is a subsequence of S
     */
    int numMatchingSubseq(string &S, vector<string> &words) {
        int sLen = S.size();
        if(sLen == 0) return 0;
        int total = 0;
        for(const auto& word : words) {
            int wordLen = word.size();
            int wordIndex = 0;
            int sIndex = 0;
            while(wordIndex < wordLen && sIndex < sLen) {
                while(sIndex < sLen && S[sIndex] != word[wordIndex]) ++sIndex;
                if(sIndex < sLen) {
                    ++wordIndex;
                    ++sIndex;
                }
            }
            if(wordIndex == wordLen) ++total;
        }
        return total;
    }
};

// Add cache to quick pass seen words
class Solution {
public:
    /**
     * @param S: a string
     * @param words: a dictionary of words
     * @return: the number of words[i] that is a subsequence of S
     */
    int numMatchingSubseq(string &S, vector<string> &words) {
        int sLen = S.size();
        if(sLen == 0) return 0;
        unordered_map<char, int> freq;
        for(auto c : S) {
            ++freq[c];
        }
        int total = 0;
        unordered_set<string> sub;
        unordered_set<string> nonSub;
        for(const auto& word : words) {
            if(sub.count(word)) {
                ++total;
                continue;
            }
            if(nonSub.count(word)) {continue;}

            int wordLen = word.size();
            int wordIndex = 0;
            int sIndex = 0;
            while(wordIndex < wordLen && sIndex < sLen) {
                if(freq.count(word[wordIndex]) == 0) break;
                while(sIndex < sLen && S[sIndex] != word[wordIndex]) ++sIndex;
                if(sIndex < sLen) {
                    ++wordIndex;
                    ++sIndex;
                }
            }
            if(wordIndex == wordLen) {
                ++total;
                sub.insert(word);
            } else {
                nonSub.insert(word);
            }
        }
        return total;
    }
};