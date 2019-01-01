class Solution {
private:
    struct WordCompare{
        bool operator()(const string& s1, const string&s2) const {
            if(s1.size() == s2.size()) {
                if(s1[0] == s2[0]) {
                    if(s1.back() == s2.back())
                    {
                        return s1 < s2;
                    } else {
                        return s1.back() < s2.back();
                    }
                } else {
                    return s1[0] < s2[0];
                }
            } else {
                return s1.size() < s2.size();
            }
        }
    };

    bool exclusive(const string& word1, const string& word2) const {
        return word1.size() != word2.size() || word1[0] != word2[0] || word1.back() != word2.back();
    }

    string getAbbr(const string& originalWord, int shortenLen) {
        int len = originalWord.size();
        return originalWord.substr(0, len - shortenLen - 1) + to_string(shortenLen) + originalWord.back();
    }
public:
    /**
     * @param dict: an array of n distinct non-empty strings
     * @return: an array of minimal possible abbreviations for every word
     */
    vector<string> wordsAbbreviation(vector<string> &dict) {
        int len = dict.size();
        if(len == 0) return {};

        vector<string> result(len);
        vector<string> newDict;
        unordered_map<string, int> wordToIndex;
        for(int i = 0; i < len; ++i) {
            const auto& word = dict[i];
            if(word.size() <= 3) {
                result[i] = word;
            } else {
                newDict.emplace_back(word);
            }
            wordToIndex[word] = i;
        }
        if(newDict.empty()) return result;

        sort(newDict.begin(), newDict.end(), WordCompare());
        len = newDict.size();
        string prevMin;
        for(int i = 0; i < len; ++i) {
            if(i == 0) {
                prevMin = newDict[i][0] + to_string(newDict[i].size() - 2) + newDict[i].back();
            }
            if(i < len - 1) {
                auto currWord = newDict[i];
                auto nextWord = newDict[i+1];
                string currAbbr;
                string nextAbbr;
                if(exclusive(currWord, nextWord)) {
                    currAbbr = getAbbr(currWord, currWord.size() - 2);
                    nextAbbr = getAbbr(nextWord, nextWord.size() - 2);
                } else {
                    int startIndex = 1;
                    // technically we dont need to check out of range because we kknow currWord and nextWord
                    // are of the same size, otherwise the if clause above will eb satisfied
                    // Plus, all words are unique so startIndex cannot be out of range, otherwise
                    // testing data is wrong. But for integraty, we check here to prevent undefined behaviour
                    while(startIndex < currWord.size() && currWord[startIndex] == nextWord[startIndex]) {
                        ++startIndex;
                    }
                    // currWord is always shorter according to sorting rules
                    if(startIndex + 4 <= currWord.size()) {
                        currAbbr = getAbbr(currWord, currWord.size() - startIndex - 2);
                        nextAbbr = getAbbr(nextWord, nextWord.size() - startIndex - 2);
                    } else {
                        currAbbr = currWord;
                        nextAbbr = nextWord;
                    }
                }
                result[wordToIndex[currWord]] = (currAbbr.size() > prevMin.size() ? currAbbr : prevMin);
                prevMin = nextAbbr;
            } else {
                result[wordToIndex[newDict.back()]] = prevMin;
            }
        }
        return result;
    }
};