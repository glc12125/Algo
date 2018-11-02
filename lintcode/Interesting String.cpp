class Solution {
private:
    bool isDigit(char c) {
        return '0' <= c && c <= '9';
    }

    bool isInteresting(const std::string& s, int index, std::unordered_map<std::string, bool>& mem) {
        if(index > s.size()) return false;
        if(index == s.size()) return true;
        
        if(mem.count(s.substr(index))) return mem[s.substr(index)];
        bool isValid = false;
        int i = index;
        std::string num;
        while(isDigit(s.at(i))) {
            num += s.at(i);
            int count = std::stoi(num);
            if(count <= s.size() - i) {
                if(isInteresting(s, i + count + 1, mem)) {
                    isValid = true;
                    break;
                }
            } else break;
            ++i;
        }
        
        mem[s.substr(index)] = isValid;
        return mem[s.substr(index)];
    }
public:
    /**
     * @param s: the string s
     * @return: check if the string is interesting
     */
    string check(string &s) {
        std::unordered_map<std::string, bool> mem;
        return isInteresting(s, 0, mem) ? "yes" : "no";
    }
};