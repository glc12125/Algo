class Solution {
private:
    bool isNum(char c) {
        // '0' - '9': [48, 57]
        if(c > 47 && c < 58) return true;
        else return false;
    }
    
    bool isInvalidNum(const std::string& numStr) {
        return numStr[0] == '0';
    }
public:
    /**
     * @param word: a non-empty string
     * @param abbr: an abbreviation
     * @return: true if string matches with the given abbr or false
     */
    bool validWordAbbreviation(string &word, string &abbr) {
        int sizeW = word.size();
        int sizeA = abbr.size();
        std::string number;
        int j = 0;
        for(int i = 0; i < sizeA; ++i) {
            const auto& c = abbr[i];
            if(isNum(c)) number += c;
            else {
                if(!number.empty()) {
                    if (isInvalidNum(number)) return false;
                    int wildNum = std::stoi(number);
                    number.clear();
                    j += wildNum;
                }
                if(word[j++] != abbr[i]) return false;
            }
        }
        if(!number.empty()) {
            if (isInvalidNum(number)) return false;
            int wildNum = std::stoi(number);
            if(sizeW - j == wildNum) return true;
            else return false;
        }
        return true;
    }
};