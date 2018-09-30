class Solution {
private:
    bool isAlphanumeric (char a) {
        return ((a >= 'a' && a <= 'z') || (a >='0' && a <= '9'));
    }
public:
    /**
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    bool isPalindrome(string &s) {
        int size = s.size();
        if(size == 0) return true;
        int left = 0;
        int right = size - 1;
        while(left < right) {
            char leftC = tolower(s[left]);
            char rightC = tolower(s[right]);
            auto leftA = isAlphanumeric(leftC);
            auto rightA = isAlphanumeric(rightC);
            if(leftA && rightA) {
                if(leftC != rightC) return false;
                ++left;
                --right;
                continue;
            }
            if (!leftA) {
                ++left;
            }
            if (!rightA) {
                --right;
            }
        }
        return true;
    }
};