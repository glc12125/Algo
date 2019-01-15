class Solution {
private:
    void dfs(int index, const vector<string>& s, string& shortened, vector<int>& result) {
        int len = s.size();
        if(index >= len) {
            return;
        }

        int shortenedLen = shortened.size();
        const auto& newWord = s[index];
        int currLen = newWord.size();
        int minLen = std::min(currLen, shortenedLen);
        while(minLen && shortened.compare(shortenedLen - minLen, minLen, newWord, 0, minLen)) {
            --minLen;
        }
        shortened += newWord.substr(minLen);
        result.push_back(shortened.find(newWord));
        dfs(index + 1, s, shortened, result);
    }

public:
    /**
     * @param s: the given strings
     * @return: Output the first occurrence of each string in `s` in the target compression string.
     */
    vector<int> wordsCompression(vector<string> &s) {
        int len = s.size();
        if(len == 0) return {};

        vector<int> result;
        string shortened;
        dfs(0, s, shortened, result);
        return result;
    }
};