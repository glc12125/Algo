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
                if(isPatternValid(p, pIndex)) return true;
                else return false;
            }
        }

        if(pIndex >= p.size()) return false;

        auto key = std::make_pair(sIndex, pIndex);
        if(mem.count(key)) return mem[key];

        bool result = false;
        if(pIndex < p.size() - 1 && p[pIndex + 1] == '*') {
            result = (isEqual(s, sIndex, p, pIndex) && match(s, sIndex + 1, p, pIndex, mem)) || match(s, sIndex, p, pIndex + 2, mem);
        } else {
            result = isEqual(s, sIndex, p, pIndex) && match(s, sIndex + 1, p, pIndex + 1, mem);
        }

        mem[key] = result;
    }

    bool isEqual(const std::string& s, int sIndex, const std::string& p, int pIndex) const {
        return p[pIndex] == '.' || p[pIndex] == s[sIndex];
    }

    bool isPatternValid(const std::string& pattern, int index) {
        if((pattern.size() - index) % 2) return false;
        int top = pattern.size();
        for(int i = index; i < top;) {
            if(pattern[i + 1] != '*') return false;
            i += 2;
        }
        return true;
    }
public:
    /**
     * @param s: A string
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(string &s, string &p) {
        if(p.size() == 0) return false;

        std::unordered_map<std::pair<int, int>, bool, PairHash> mem;
        return match(s, 0, p, 0, mem);
    }
};