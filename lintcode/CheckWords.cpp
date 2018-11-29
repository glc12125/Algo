class Solution {
private:
    bool dfs(string s, unordered_set<string>& str, unordered_map<string, bool>& mem) {
        if(s.size() == 0) {
            return true;
        }

        if(mem.count(s)) {
            return mem[s];
        }

        mem[s] = false;
        if(str.count(s) == 0) {
            mem[s] = false;
            return false;
        }


        for(int i = 0; i < s.size(); ++i) {
            if(dfs(s.substr(0, i) + s.substr(i + 1), str, mem)) {
                mem[s] = true;
                break;
            }
        }

        return mem[s];
    }
public:
    /**
     * @param s:
     * @param str:
     * @return: Output whether this combination meets the condition
     */
    bool checkWord(string &s, vector<string> &str) {
        unordered_set<string> dict;
        for(const auto& word : str) {
            if(word.size() > s.size()) return false;
            dict.insert(word);
        }
        unordered_map<string, bool> mem;

        return dfs(s, dict, mem);
    }
};