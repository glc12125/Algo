// DP, time O(N^2)
class Solution {
private:

    int getMaxLenInDict(const unordered_set<string> &dict) {
        int maxLen = INT_MIN;
        for(const auto& word : dict) {
            maxLen = std::max(maxLen, (int)word.size());
        }
        return maxLen;
    }
public:
    /*
     * @param s: A string
     * @param dict: A dictionary of words dict
     * @return: A boolean
     */
    bool wordBreak(string &s, unordered_set<string> &dict) {
        if(s.size() == 0 && dict.size() == 0) return true;
        if(s.size() == 0 || dict.size() == 0) return false;

        int len = s.size();
        int maxLength = getMaxLenInDict(dict);
        vector<bool> canSegment(len + 1, false);
        canSegment[0] = true;
        for (int i = 1; i <= len; i++) {
            canSegment[i] = false;
            for (int j = 1; j <= maxLength && j <= i; j++) {
                if (!canSegment[i - j]) {
                    continue;
                }
                if (dict.count(s.substr(i - j, j))) {
                    canSegment[i] = true;
                    break;
                }
            }
        }

        return canSegment[s.size()];
    }
};

//DFS
class Solution {
private:
    bool dfs(const string &s, const unordered_set<string> &dict, int maxLen, int index, unordered_map<int, bool>& mem){
        if(mem.count(index)) return mem[index];
        int len = s.size();
        if(index == len) return true;

        bool canBreak = false;
        for(int i = index; i < len; ++i) {
            int candidateLen = i - index + 1;
            if(candidateLen > maxLen) break;
            const auto& candidate = s.substr(index, candidateLen);
            if(dict.count(candidate)) {
                if(dfs(s, dict, maxLen, i + 1, mem)) {
                    canBreak = true;
                    break;
                }
            }
        }

        if(dict.count(s.substr(index))) canBreak = true;
        mem[index] = canBreak;
        return canBreak;
    }

    int getMaxLenInDict(const unordered_set<string> &dict) {
        int maxLen = INT_MIN;
        for(const auto& word : dict) {
            maxLen = std::max(maxLen, (int)word.size());
        }
        return maxLen;
    }
public:
    /*
     * @param s: A string
     * @param dict: A dictionary of words dict
     * @return: A boolean
     */
    bool wordBreak(string &s, unordered_set<string> &dict) {
        if(s.size() == 0 && dict.size() == 0) return true;
        if(s.size() == 0 || dict.size() == 0) return false;
        unordered_map<int, bool> mem;
        int maxLen = getMaxLenInDict(dict);
        return dfs(s, dict, maxLen, 0, mem);
    }
};