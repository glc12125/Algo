class Solution {
private:
    bool isAlphabet(char c) {
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
    }
public:
    /**
     * @param licensePlate: a string
     * @param words: List[str]
     * @return: return a string
     */
    string shortestCompletingWord(string &licensePlate, vector<string> &words) {
        unordered_map<char, int> lookupTable;
        for(auto c : licensePlate) {
            if(isAlphabet(c)) {
                ++lookupTable[tolower(c)];
            }
        }

        string shortest;
        for(const auto& word : words) {
            auto workingCopy = lookupTable;
            for(auto c : word) {
                if(workingCopy.count(c)) {
                    if(--workingCopy[c] == 0) workingCopy.erase(c);
                }
            }
            if(workingCopy.size() == 0 && (shortest.empty() || (word.size() < shortest.size()))) {
                shortest = word;
            }
        }

        return shortest;
    }
};