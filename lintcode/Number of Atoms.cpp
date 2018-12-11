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

//Iterative, time O(N^2), space O(N)
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

public:
    /**
     * @param formula: a string
     * @return: return a string
     */
    string countOfAtoms(string &formula) {
        int len = formula.size();
        if(len == 0) return "";

        int index = 0;
        stack<pair<string, int>> parsedElements;
        stack<pair<string, int>> parsingElements;
        while(index < len) {
            if(formula[index] == '(') {
                parsedElements.push(make_pair(string(1, '('), 1));
                ++index;
            } else if(formula[index] == ')') {
                // multiple current counters by digits following the
                // closing bracket
                ++index;
                int count = 0;
                while(index < len && isDigit(formula[index])) {
                    count = count * 10 + (formula[index++] - '0');
                }
                count = std::max(1, count);
                while(parsedElements.top().first != "(") {
                    parsingElements.push(parsedElements.top());
                    parsedElements.pop();
                }
                parsedElements.pop();
                while (!parsingElements.empty()) {
                    auto elementCountPair = parsingElements.top();
                    elementCountPair.second *= count;
                    parsedElements.push(elementCountPair);
                    parsingElements.pop();
                }
            } else if(isUpper(formula[index])){
                string element(1, formula[index++]);
                while(index < len && isLower(formula[index])) {
                    element += formula[index++];
                }
                int count = 0;
                while(index < len && isDigit(formula[index])) {
                    count = count * 10 + (formula[index++] - '0');
                }
                count = std::max(1, count);
                parsedElements.push(make_pair(element, count));
            }
        }
        map<string, int> overalCounters;
        while(!parsedElements.empty()) {
            auto elementCountPair = parsedElements.top();
            overalCounters[elementCountPair.first] += elementCountPair.second;
            parsedElements.pop();
        }

        string result;
        for(const auto& p : overalCounters) {
            result += p.first;
            if(p.second > 1) {
                result += to_string(p.second);
            }
        }
        return result;

    }
};