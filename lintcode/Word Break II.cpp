class Solution {
private:
    std::vector<std::string> dfs(const std::string& s, int index, const std::unordered_set<std::string> &wordDict, std::unordered_map<std::string, std::vector<std::string> >& mem) {

        if(mem.count(s.substr(index))) {
            return mem[s.substr(index)];
        }
        int len = s.size();
        std::vector<std::string> result;
        if(index == len) {
            return result;
        }

        for(int i = index; i < len; ++i) {
            const auto& candidate = s.substr(index, i - index + 1);
            if(wordDict.count(candidate)) {
                auto partitions = dfs(s, i + 1, wordDict, mem);
                for(auto& partition : partitions) {
                    result.push_back(candidate + " " + partition);
                }
            }
        }

        if(wordDict.count(s.substr(index))) result.push_back(s.substr(index));
        mem[s.substr(index)] = result;
        return result;
    }
public:
    /*
     * @param s: A string
     * @param wordDict: A set of words.
     * @return: All possible sentences.
     */
    vector<string> wordBreak(string &s, unordered_set<string> &wordDict) {
        if(s.size() == 0 || wordDict.size() == 0) return std::vector<std::string>();

        std::unordered_map<std::string, std::vector<std::string> > mem;
        return dfs(s, 0, wordDict, mem);
    }
};
