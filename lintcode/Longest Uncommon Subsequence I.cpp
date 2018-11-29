class Solution {
public:
    /**
     * @param a: a string
     * @param b: a string
     * @return: return a integer
     */
    int findLUSlength(string &a, string &b) {
        if(a == b) return -1;
        else {
            return std::max(a.size(), b.size());
        }
    }
};