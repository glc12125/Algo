class Solution {
private:
    void findPalindrom(const std::string& s, int left, int right, int len, int& maxLen, int& start) {
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
            maxLen = len;
            start = left + 1;
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
        int start = 0;
        int left = 0;
        int right = 0;
        int maxLen = 1;
        for(int i = 1; i < size; ++i) {
            int len = 1;
            if(s[i] == s[i-1]) {
                left = i - 2;
                right = i + 1;
                len = 2;
                findPalindrom(s, left, right, len, maxLen, start);
            }
            len = 1;
            left = i - 2;
            right = i;
            findPalindrom(s, left, right, len, maxLen, start);
        }
        return s.substr(start, maxLen);
    }
};

// A cleaner approache, we don't really need to compare left and right when calling findPalindrom
// A middle point can be either an element or between two elements.

class Solution {
private:
    void findPalindrom(const std::string& s, int left, int right, int& maxLen, int& start) {
        int size = s.size();
        while(left > -1 && right < size) {
            if(s[left] == s[right]) {
                --left;
                ++right;
            } else break;
        }
        int len = right - left - 1;
        if(maxLen < len) {
            maxLen = len;
            start = left + 1;
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
        int start = 0;
        int maxLen = 1;
        for(int i = 0; i < size; ++i) {
            findPalindrom(s, i, i, maxLen, start);
            findPalindrom(s, i, i + 1, maxLen, start);
        }
        return s.substr(start, maxLen);
    }
};

// Dynamic programming approach
class Solution {
public:
    /**
     * @param s: input string
     * @return: the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        int size = s.size();
        if(size == 0) return "";

        int dp[size][size] = {0};
        for(int i = 0; i < size; ++i) {
            dp[i][i] = 1;
            if(i > 0) dp[i][i-1] = 1;
        }
        int start = 0;
        int maxLen = 1;
        for(int len = 2; len < size + 1; ++len) {
            for(int i = 0; i < size - len + 1; ++i) {
                int j = i + len - 1;
                dp[i][j] = dp[i+1][j-1] && s[i] == s[j] ? 1 : 0;
                if(dp[i][j] && len > maxLen) {
                    maxLen = len;
                    start = i;
                }
            }

        }
        return s.substr(start, maxLen);
    }
};
