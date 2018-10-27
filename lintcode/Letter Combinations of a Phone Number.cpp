class Solution {
private:
    const std::vector<std::string> m_keyboard { " ", "", "abc", "def", // '0','1','2',...
            "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    void dfs(const std::string& digits, int index, std::string& answer, std::vector<std::string>& results){
        if(index >= digits.size()) {
            results.push_back(answer);
            return;
        }

        const auto& choices = m_keyboard[digits[index] - '0'];
        for(const auto& c : choices) {
            answer.push_back(c);
            dfs(digits, index + 1, answer, results);
            answer.pop_back();
        }
    }
public:
    /**
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    vector<string> letterCombinations(string &digits) {
        if(digits.size() == 0) return {};
        std::vector<std::string> results;
        std::string answer;
        dfs(digits, 0, answer, results);
        return results;
    }
};