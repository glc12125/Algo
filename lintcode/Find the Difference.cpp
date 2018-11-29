class Solution {
public:
    /**
     * @param s: a string
     * @param t: a string
     * @return: the letter that was added in t
     */
    char findTheDifference(string &s, string &t) {
        char r=0;
        string combined(s+t);
        for(char c : combined) r ^=c;
        return r;
    }
};