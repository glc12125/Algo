class Solution {
private:
    void dfs(const std::string& s, int index, std::unordered_map<char, int>& parenCount, std::unordered_set<std::string>& results){
        //std::cout << "s: " << s << ", index: " << index << "\n";

        if(parenCount['('] == 0 && parenCount[')'] == 0) {
            if(isValid(s)) results.insert(s);
            return;
        }
        int len = s.size();
        for(int i = index; i < len; ++i) {
            if(i > 0 && s[i] == s[i-1] && i > index) continue;

            if(s[i] == '(' && parenCount['('] > 0) {
                --parenCount['('];
                dfs(s.substr(0, i) + s.substr(i+1), i, parenCount, results);
                ++parenCount['('];
            }

            if(s[i] == ')' && parenCount[')'] > 0) {
                --parenCount[')'];
                dfs(s.substr(0, i) + s.substr(i+1), i , parenCount, results);
                ++parenCount[')'];
            }
        }
    }

    bool isValid(const std::string& s) {
        std::stack<char> st;
        for(const auto& c : s) {
            if(c == '(') st.push('(');
            else if (c == ')') {
                if(st.size() > 0 && st.top() == '(') {
                    st.pop();
                } else return false;
            }
        }
        return st.size() == 0;
    }

    void getInvalidCounts(const std::string& s, std::unordered_map<char, int>& parenCount) {
        std::stack<char> st;
        for(const auto& c : s) {
            if(c == '(') {
                st.push('(');
                ++parenCount['('];
            }
            else if (c == ')') {
                if(st.size() > 0 && st.top() == '(') {
                    st.pop();
                    --parenCount['('];
                } else {
                    ++parenCount[')'];
                }
            }
        }
    }
public:
    /**
     * @param s: The input string
     * @return: Return all possible results
     */
    vector<string> removeInvalidParentheses(string &s) {
        std::unordered_map<char, int> parenCount;
        getInvalidCounts(s, parenCount);
        //std::cout << "parenCount[(]: " << parenCount['('] << ", parenCount[)]: " << parenCount[')'] << "\n";

        std::unordered_set<std::string> results;
        std::string answer;
        dfs(s, 0, parenCount, results);
        if(results.size() == 0) return std::vector<std::string>(1, "");
        else return std::vector<std::string>(results.begin(), results.end());
    }
};