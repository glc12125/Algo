class Solution {
private:
    bool isUpper(const char& c) {
        return ('A' <= c && c <= 'Z');
    }
    bool isLower(const char& c) {
        return ('a' <= c && c <= 'z');
    }

    bool isDigit(const char& c) {
        return ('0' <= c && c <= '9');
    }

    map<string, int> dfs(const string& formula, int& index) {
        map<string, int> result;
        int len = formula.size();
        if(index >= len) return result;

        while(index < len && formula[index] != ')') {
            if(isUpper(formula[index])) {
                string key(1, formula[index++]);
                while(index < len && isLower(formula[index])) {
                    key += formula[index++];
                }
                int count = 0;
                while(index < len && isDigit(formula[index])) {
                    count = count * 10 + (formula[index++] - '0');
                }
                count = std::max(1, count);
                result[key] += count;
            } else if(formula[index] == '(') {
                ++index;
                const auto& partialResult = dfs(formula, index);
                int count = 0;
                while(index < len && isDigit(formula[index])) {
                    count = count * 10 + (formula[index++] - '0');
                }
                count = std::max(1, count);
                for(const auto& p : partialResult) {
                    result[p.first] += p.second * count;
                }
            }
        }

        if(formula[index] == ')') {
            ++index;
            return result;
        }

        return result;

    }
public:
    /**
     * @param formula: a string
     * @return: return a string
     */
    string countOfAtoms(string &formula) {
        int index = 0;
        const auto& counters = dfs(formula, index);
        string result;
        for(const auto& p : counters) {
            result += p.first;
            if(p.second > 1) {
                result += to_string(p.second);
            }
        }
        return result;

    }
};