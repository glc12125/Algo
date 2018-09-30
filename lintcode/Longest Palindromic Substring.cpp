class Solution {
private:
    void findPalindrom(const std::string& s, int left, int right, int len, int& maxLen, std::string& result) {
        //std::cout << "[findPalindrom] left: " << left << ", right: " << right << "\n";
        int size = s.size();
        while(left > -1 && right < size) {
            if(s[left] == s[right]) {
                --left;
                ++right;
                len+=2;
            } else break;
        }
        if(maxLen < len) {
            //std::cout << "left: " << left << ", right: " << right << ", len: " << len << "\n";
            maxLen = len;
            //int width = ((right - left) % 2 ? right - left : right - left - 1); 
            result = s.substr(left + 1, right - left - 1);
        }
    }
public:
    /**
     * @param s: input string
     * @return: the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        int size = s.size();
        if(size == 0) return "";
        else if (size == 1) return s.substr(0, 1);
        std::string result;
        int left = 0;
        int right = 0;
        int maxLen = 1;
        for(int i = 1; i < size; ++i) {
            int len = 1;
            if(s[i] == s[i-1]) {
                left = i - 2;
                right = i + 1;
                len = 2;
                findPalindrom(s, left, right, len, maxLen, result);
            }
            len = 1;
            left = i - 2;
            right = i;
            findPalindrom(s, left, right, len, maxLen, result);
        }
        return result;
    }
};