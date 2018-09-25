class Solution {
private:
    void btAppend(int open, int close, string current, vector<string>& result) {
        if(open == 0 && close == 0) {
            result.push_back(current);
            return;
        }
        //std::cout << "current: " << current << "\n";
        if(open > 0) {
            btAppend(open - 1, close, current + "(", result);
        }
        if (close > 0 && close > open) {
            btAppend(open, close - 1, current + ")", result);
        }
    }
public:
    /**
     * @param n: n pairs
     * @return: All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        btAppend(n, n, "", result);
        return result;
    }
};