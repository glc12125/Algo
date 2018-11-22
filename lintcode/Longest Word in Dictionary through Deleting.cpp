class Solution {
private:
    bool isSubsequency(const string& main, const string& candidate) {
        int lenMain = main.size();
        int lenCandidate = candidate.size();
        if(lenCandidate > lenMain) return false;
        int i = 0;
        int j = 0;
        while(i < lenMain && j < lenCandidate) {
            if(main.at(i) == candidate.at(j)) {
                ++i;
                ++j;
            } else if(i + 1 == lenMain && j + 1 <= lenCandidate) {
                return false;
            } else ++i;
        }
        return j == lenCandidate;
    }
public:
    /**
     * @param s: a string
     * @param d: List[str]
     * @return: return a string
     */
    string findLongestWord(string &s, vector<string> &d) {
        if(d.size() == 0) return "";

        sort(d.begin(), d.end(), [](const string& s1, const string& s2){
            return (s1.size() > s2.size()) || ((s1.size() == s2.size()) && (s1 < s2));
        });

        for(const auto& candidate : d) {
            if(isSubsequency(s, candidate)) return candidate;
        }
        return "";
    }
};