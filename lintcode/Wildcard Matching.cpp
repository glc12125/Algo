class Solution {
private:
    struct PairHash{
        size_t operator()(const std::pair<int, int>& p) const {
            auto hFirst = std::hash<int>()(p.first);
            auto hSecond = std::hash<int>()(p.second);
            return hFirst ^ hSecond;
        }
    };

    bool match(const std::string& s, int sIndex, const std::string& p, int pIndex, std::unordered_map<std::pair<int, int>, bool, PairHash>& mem) {
        if(sIndex >= s.size()) {
            if(pIndex >= p.size()) return true;
            else {
                if(isPatternAllStars(p, pIndex)) return true;
                else return false;
            }
        }

        if(pIndex >= p.size()) return false;

        auto key = std::make_pair(sIndex, pIndex);
        if(mem.count(key)) return mem[key];

        bool result = false;
        if(p[pIndex] != '*') {
            if(p[pIndex] == '?') result = match(s, sIndex + 1, p, pIndex + 1, mem);
            else {
                result = (p[pIndex] == s[sIndex] ?  match(s, sIndex + 1, p, pIndex + 1, mem) : false);
            }
        } else {
            result = match(s, sIndex + 1, p, pIndex, mem) || match(s, sIndex, p, pIndex + 1, mem);
        }

        mem[key] = result;
    }

    bool isPatternAllStars(const std::string& pattern, int index) {
        for(int i = index; i < pattern.size(); ++i) {
            if(pattern[i] != '*') return false;
        }
        return true;
    }
public:
    /**
     * @param s: A string
     * @param p: A string includes "?" and "*"
     * @return: is Match?
     */
    bool isMatch(string &s, string &p) {
        if(p.size() == 0) return false;

        std::unordered_map<std::pair<int, int>, bool, PairHash> mem;
        return match(s, 0, p, 0, mem);
    }
};