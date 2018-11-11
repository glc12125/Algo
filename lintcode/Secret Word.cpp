// Sliding Window approach, time O(M*N) space O(1)
class Solution {
private:
    bool patternMatch(const string& s, const string &word, int start) {
        int end = word.size() + start;
        vector<char> alphabets(26, '0');
        unordered_set<char> chosen;
        for(int i = start; i < end; ++i) {
            int wordIndex = i - start;
            int index = word.at(wordIndex) - 'a';
            if(alphabets[index] == '0') {
                if(chosen.count(s.at(i))) return false;
                else {
                    alphabets[index] = s.at(i);
                    chosen.insert(s.at(i));
                }
            } else {
                if(alphabets[index] != s.at(i)) return false;
            }
        }

        return true;
    }
public:
    /**
     * @param s: the long string
     * @param word: the secrect word
     * @return: whether a substring exists in the string can be transformed by the above encoding rule
     */
    string getAns(string &s, string &word) {
        int wordSize = word.size();
        int sSize = s.size();
        if(sSize == 0 || wordSize == 0 || sSize < wordSize) return "no";

        int end = sSize - wordSize;
        for(int i = 0; i <= end; ++i) {
            if(patternMatch(s, word, i)) return "yes";
        }

        return "no";
    }
};

// DFS
class Solution {
private:
    bool dfs(const string& s, const string& word, int sIndex, int wordIndex, std::unordered_map<char, char>& values, std::unordered_set<char>& chosen) {
        //std::cout << "sIndex: " << sIndex << ", wordIndex: " << wordIndex << "\n";
        int sLen = s.size();
        int wordLen = word.size();
        if(sIndex == sLen) return (wordLen == wordIndex);
        if(wordLen == wordIndex) return true;

        char p = word[wordIndex];
        if(values.count(p)) {
            auto v = values[p];
            if(s[sIndex] != v) return false;
            return dfs(s, word, sIndex + 1, wordIndex + 1, values, chosen);
        }

        for(int i = sIndex; i < sLen; ++i) {
            auto candidateV = s[i];
            if(chosen.count(candidateV)) return false;
            values[p] = candidateV;
            chosen.insert(candidateV);
            if(dfs(s, word, i + 1, wordIndex + 1, values, chosen)) return true;
            chosen.erase(candidateV);
            values.erase(p);
        }

        return false;
    }
public:
    /**
     * @param s: the long string
     * @param word: the secrect word
     * @return: whether a substring exists in the string can be transformed by the above encoding rule
     */
    string getAns(string &s, string &word) {
        if(s.size() == 0 || word.size() == 0 || s.size() < word.size()) return "no";
        std::unordered_map<char, char> values;
        std::unordered_set<char> chosen;
        return dfs(s, word, 0, 0, values, chosen) ? "yes" : "no";
    }
};