class Solution {
public:
    /**
     * @param word: a string
     * @return: return a boolean
     */
    bool detectCapitalUse(string &word) {
        // write your code here
        for(int i=1; i<word.size(); i++){
            if(isupper(word[i]) &&islower(word[i-1])){
                 return false;
            }
            if(i> 1 && islower(word[i]) && isupper((word[i-1]))){
                return false;
            }
        }
        return true;
    }
};