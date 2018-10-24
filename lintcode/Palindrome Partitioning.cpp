class Solution {
private:
    void dfsPartition(const std::string& s, int index, std::vector<std::string>& splits, std::vector<std::vector<std::string> >& results) {
        int len = s.size();
        if(index >= len) {
            results.push_back(splits);
            return;
        }

        for(int i = index; i < len; ++i) {
            const std::string& candidate = s.substr(index, i - index + 1);
            if(isPalindrome(candidate)) {
                splits.push_back(candidate);
                dfsPartition(s, i + 1, splits, results);
                splits.pop_back();
            }
        }
    }

    bool isPalindrome(const std::string& s) {
        int start = 0;
        int end = s.size() - 1;
        while(start < end) {
            if(s[start] != s[end]) return false;
            ++start;
            --end;
        }
        return true;
    }
public:
    /*
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string &s) {
        std::vector<std::vector<std::string> > results;
        std::vector<std::string> splits;
        dfsPartition(s, 0, splits, results);
        return results;
    }
};