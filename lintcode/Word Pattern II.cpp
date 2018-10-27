class Solution {
private:
    bool dfs(const std::string& pattern, int patternIndex, const std::string& str, int strIndex, std::unordered_map<char, std::string>& values, std::unordered_set<std::string>& chosenPatterns) {
        int patternLen = pattern.size();
        int strLen = str.size();
        if(patternIndex == patternLen) return strIndex == strLen;

        char p = pattern[patternIndex];
        // If existing pattern
        if(values.count(p)) {
            const auto& value = values[p];
            if(value.size() > strLen - strIndex) return false;
            if(value != str.substr(strIndex, value.size())) return false;
            return dfs(pattern, patternIndex + 1, str, strIndex + value.size(), values, chosenPatterns);
        }

        for(int i = strIndex; i < strLen; ++i) {
            const auto& candidateValue = str.substr(strIndex, i - strIndex + 1);
            if(chosenPatterns.count(candidateValue)) continue;
            values[p] = candidateValue;
            chosenPatterns.insert(candidateValue);
            if(dfs(pattern, patternIndex + 1, str, i + 1, values, chosenPatterns)) return true;
            chosenPatterns.erase(candidateValue);
            values.erase(p);
        }

        return false;
    }
public:
    /**
     * @param pattern: a string,denote pattern string
     * @param str: a string, denote matching string
     * @return: a boolean
     */
    bool wordPatternMatch(string &pattern, string &str) {
        if(pattern.size() == 0 || str.size() == 0 || pattern.size() > str.size()) return false;
        std::unordered_map<char, std::string> values;
        std::unordered_set<std::string> chosenPatterns;
        return dfs(pattern, 0, str, 0, values, chosenPatterns);
    }
};