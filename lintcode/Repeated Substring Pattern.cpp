class Solution {
public:
    /**
     * @param s: a string
     * @return: return a boolean
     */
    bool repeatedSubstringPattern(string &s) {
        // write your code here
        auto size = s.size();
        if(size == 0) return false;
        else if (size == 1) return true;
        int mid = size / 2;
        if(size%2 == 0){
            for(int i = 0, j = mid;
                i < mid && j < size;
                ++i, ++j
            ){
                if(s[i] != s[j]) return false;
            }
        } else {
            if (s[mid] != s[mid-1]) return false;
        }

        return true;
    }
};