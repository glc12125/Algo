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

// Iterative
class Solution {
private:
    struct Element{
        int m_left;
        int m_right;
        string m_curr;
        Element() = default;
        Element(int l, int r, const string& curr) : m_left(l), m_right(r), m_curr(curr) {}
    };
public:
    /**
     * @param n: n pairs
     * @return: All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        stack<Element> q; // Actually, it does not matter if it is a stack or a queue, because order does not matter
        q.push(Element(0, 0, ""));

        while(!q.empty()) {
            auto curr = q.top();
            q.pop();
            if(curr.m_left == n && curr.m_right == n) {
                result.push_back(curr.m_curr);
            } else {
                if(curr.m_left < n) {
                    q.push(Element(curr.m_left + 1, curr.m_right, curr.m_curr + "("));
                }
                if(curr.m_left > curr.m_right) {
                    q.push(Element(curr.m_left, curr.m_right + 1, curr.m_curr + ")"));
                }
            }
        }

        return result;
    }
};