class Solution {
private:
    bool isSimilar(const std::string& s1, const std::string& s2, std::unordered_map<std::string, std::set<std::string> >& m) {
        if(s1 == s2) return true;
        return m[s1].count(s2) > 0;
    }
public:
    /**
     * @param words1: a list of string
     * @param words2: a list of string
     * @param pairs: a list of string pairs
     * @return: return a boolean, denote whether two sentences are similar or not
     */
    bool isSentenceSimilarity(vector<string> &words1, vector<string> &words2, vector<vector<string>> &pairs) {
        int size1 = words1.size();
        int size2 = words2.size();
        if(size1 != size2) return false;
        
        std::unordered_map<std::string, std::set<std::string> > m;
        for(auto pair : pairs) {
            m[pair[0]].insert(pair[1]);
            m[pair[1]].insert(pair[0]);
        }
        for(int i = 0; i < size1; ++i) {
            if(!isSimilar(words1[i], words2[i], m)) return false;
        }
        return true;
    }
};