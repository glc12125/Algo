class Solution {
private:
    bool memoSearch(const string& s1, const string& s2, unordered_map<string, bool>& memo) {
        string key = s1 + "_" + s2;
        if(memo.count(key)) return memo[key];

        int len = s1.size();
        if(len == 1) return s1[0] == s2[0];

        for(int k = 1; k < len; ++k) {
            if((memoSearch(s1.substr(0, k), s2.substr(0, k), memo) && memoSearch(s1.substr(k, len - k), s2.substr(k, len - k), memo)) || (memoSearch(s1.substr(0, k), s2.substr(len - k, k), memo) && memoSearch(s1.substr(k, len - k), s2.substr(0, len - k), memo))) {
                memo[key] = true;
                return true;
            }
        }

        memo[key] = false;
        return false;
    }
public:
    /**
     * @param s1: A string
     * @param s2: Another string
     * @return: whether s2 is a scrambled string of s1
     */
    bool isScramble(string &s1, string &s2) {
        if(s1.size() != s2.size()) return false;

        unordered_map<string, bool> memo;
        return memoSearch(s1, s2, memo);
    }
};