class Solution {
public:
    /**
     * @param s: the given string
     * @return: if a permutation of the string could form a palindrome
     */
    bool canPermutePalindrome(string &s) {
        std::unordered_map<char, int> uM;
        for(auto c : s) {
            if(uM[c] > 0) --uM[c];
            else ++uM[c];
        }
        int oddCount = 0;
        for(auto it : uM) {
            if(it.second > 0) {
                if(++oddCount > 1) break;
            }
        }
        if(oddCount > 1) return false;
        else return true;
    }
};