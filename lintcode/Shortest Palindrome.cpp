class Solution {
private:
    bool isPalindrome(const string& s) {
        int start = 0;
        int end = s.size() - 1;
        while(start < end) {
            if(s.at(start++) != s.at(end--)) return false;
        }
        return true;
    }
public:
    /**
     * @param str: String
     * @return: String
     */
    string convertPalindrome(string &str) {
        int len = str.size();
        if(len == 0) return "";
        if(len == 1) return str;

        int start = 0;
        for(int l = 0; l <= len; ++l) {
            const auto& candidate = str.substr(0, len - l);
            if(isPalindrome(candidate)) {
                start = len - l;
                break;
            }
        }
        string result = str.substr(start);
        reverse(result.begin(), result.end());
        return result + str;
    }
};