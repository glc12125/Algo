class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        string result;
        for(const auto& s : strs) {
            for(char c : s) {
                if(c == '|') {
                    result += "||";
                } else {
                    result += c;
                }
            }
            result += "|;";
        }
        return result;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        vector<string> result;
        int len = str.size();
        string word;
        for(int i = 0; i < len; ++i) {
            if(str.at(i) == '|') {
                if(str.at(i+1) == '|') {
                    word += '|';
                    ++i;
                } else {
                    result.push_back(word);
                    word.clear();
                    ++i;
                }
            } else {
                word += str.at(i);
            }
        }
        return result;
    }
};