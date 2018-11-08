class Solution {
private:

    bool isNumeric(char c) {
        return '0' <= c && c <= '9';
    }

    string divideAndConquer(const string& s, int& index) {
        int len = s.size();
        //if(index == len) return "";

        string current;
        string digit;
        while(index < len) {
            char currentChar = s[index];
            if (isNumeric(currentChar)) {
                digit += currentChar;
                ++index;
            } else if (currentChar == '[') {
                int repeatNum = std::stoi(digit);
                ++index;
                string expanded = divideAndConquer(s, index);
                while(repeatNum-- > 0) {
                    current += expanded;
                }
                ++index;
                digit.clear();
            } else if (currentChar == ']') {
                return current;
            } else {
                current += currentChar;
                ++index;
            }
        }

        return current;
    }
public:
    /**
     * @param s: an expression includes numbers, letters and brackets
     * @return: a string
     */
    string expressionExpand(string &s) {
        int len = s.size();
        if(len == 0) return "";
        int index = 0;
        return divideAndConquer(s, index);

    }
};