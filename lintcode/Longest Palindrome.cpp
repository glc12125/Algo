class Solution {
public:
    /**
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    int longestPalindrome(string &s) {
        int table[128] = {0};
        
        for(auto c : s) ++table[c];
        
        int totalNum = 0;
        bool hasOdd = false;
        for(auto i : table) {
            if(i % 2 == 0) totalNum += i;
            else {
                hasOdd = true;
                totalNum += (i - 1);
            }
        }
        
        return hasOdd ? totalNum + 1: totalNum;
    }
};