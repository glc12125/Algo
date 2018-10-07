class Solution {
private:
    bool isPalindrome(const std::string& s, int left, int right) {
        while(left < right) {
            if(s[left] == s[right]) {
                ++left;
                --right;
            } else return false;
        }
        return true;
    }
public:
    /**
     * @param s: a string
     * @return: nothing
     */
    bool validPalindrome(string &s) {
        int size = s.size();
        if(size < 2) return true;
        int start = 0;
        int end = size - 1;
        while(start < end) {
            if(s[start] == s[end]) {
                ++start;
                --end;
            } else {
                return isPalindrome(s, start + 1, end) ||
                       isPalindrome(s, start, end - 1);
            }
        }
        return true;
    }
};