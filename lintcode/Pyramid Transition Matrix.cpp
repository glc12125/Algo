class Solution {
private:
    bool populateNextBottm(const string& twoChar, const vector<string>& allowed, vector<vector<char>>& nextBottom, int index) {
        for(const auto& triple : allowed) {
            bool allow = true;
            for(int i = 0; i < 2; ++i) {
                if(twoChar[i] != triple[i]) {
                    allow = false;
                    break;
                }
            }
            if(allow) nextBottom[index].push_back(triple[2]);
        }
        return !nextBottom[index].empty();
    }

    void dfsGetLine(const vector<vector<char>>& nextBottom, const string& current, int index, vector<string>& candidates) {
        if(index == nextBottom.size()) {
            candidates.push_back(current);
            return;
        }

        int len = nextBottom[index].size();
        for(int i = 0; i < len; ++i) {
            dfsGetLine(nextBottom, current + nextBottom[index][i], index + 1, candidates);
        }
    }

    bool dfs(const string& bottom, const vector<string>& allowed, unordered_map<string, bool>& mem) {
        int len = bottom.size();
        if(len == 1) return true;
        if(mem.count(bottom)) return mem[bottom];

        vector<vector<char>> nextBottom(len - 1, vector<char>());
        bool bottomAllowed = true;
        for(int i = 0; i < len - 1; ++i) {
            if(!populateNextBottm(bottom.substr(i, 2), allowed, nextBottom, i)) {
                bottomAllowed = false;
                break;
            }
        }

        if(bottomAllowed) {
            vector<string> candidates;
            dfsGetLine(nextBottom, "", 0, candidates);
            bool canBuild = false;
            for(const auto& candidate : candidates) {
                if(dfs(candidate, allowed, mem)) {
                    canBuild = true;
                    break;
                }
            }
            mem[bottom] = canBuild;
        } else {
            mem[bottom] = false;
        }
        return mem[bottom];
    }
public:
    /**
     * @param bottom: a string
     * @param allowed: a list of strings
     * @return: return a boolean
     */
    bool pyramidTransition(string &bottom, vector<string> &allowed) {
        int len = bottom.size();
        if(len < 2) return false;
        unordered_map<string, bool> mem;
        return dfs(bottom, allowed, mem);
    }
};

// More effective memoisation search, which saves the tuple search result
class Solution {
private:
    bool dfs(const string &pre, int start, string cur, unordered_map<string, unordered_set<char>> &mp) {
        if(pre.size() == 1) return true;

        if(start == pre.size()-1) {
            // Dive to next line
            return dfs(cur, 0, "", mp);
        } else {
            // Still on the same bottom
            const auto& sub = pre.substr(start, 2);
            if(mp.count(sub)) {
                for(const auto &c : mp[sub]){
                    if(dfs(pre, start + 1, cur + c, mp)) return true;
                }
            }
        }
        return false;
    }
public:
    /**
     * @param bottom: a string
     * @param allowed: a list of strings
     * @return: return a boolean
     */
    bool pyramidTransition(string &bottom, vector<string> &allowed) {
        int len = bottom.size();
        if(len < 2) return false;

        unordered_map<string, unordered_set<char>> mp;
        for(const auto &s:allowed) {
            mp[s.substr(0,2)].insert(s.back());
        }
        return dfs(bottom, 0, "", mp);
    }
};