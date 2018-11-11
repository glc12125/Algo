class Solution {
private:
    bool isMatch(const string& source, const string& target) {
        int lenS = source.size();
        int lenT = target.size();
        if(lenS < lenT) return false;

        int j = 0;
        for(int i = 0; i < lenS; ++i) {
            if(source[i] == target[j]) {
                if(++j == lenT) return true;
            }
        }

        return j == lenT;
    }
public:
    /**
     * @param target: the target string
     * @param s:
     * @return: output all strings containing target  in s
     */
    vector<string> getAns(string &target, vector<string> &s) {
        vector<string> result;

        for(const auto& word : s) {
            if(isMatch(word, target)) result.push_back(word);
        }
        return result;
    }
};