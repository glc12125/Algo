class Solution {
private:

    bool isNumeric(char c) {
        return '0' <= c && c <= '9';
    }

    string divideAndConquer(const string& s, int& index) {
        int len = s.size();
        //if(index == len) return "";

        string current;
        string digit;
        while(index < len) {
            char currentChar = s[index];
            if (isNumeric(currentChar)) {
                digit += currentChar;
                ++index;
            } else if (currentChar == '[') {
                int repeatNum = std::stoi(digit);
                ++index;
                string expanded = divideAndConquer(s, index);
                while(repeatNum-- > 0) {
                    current += expanded;
                }
                ++index;
                digit.clear();
            } else if (currentChar == ']') {
                return current;
            } else {
                current += currentChar;
                ++index;
            }
        }

        return current;
    }
public:
    /**
     * @param s: an expression includes numbers, letters and brackets
     * @return: a string
     */
    string expressionExpand(string &s) {
        int len = s.size();
        if(len == 0) return "";
        int index = 0;
        return divideAndConquer(s, index);

    }
};

// Non recursive using stack time O(n^2)
class Solution {
private:
    bool isNumeric(char c) {
        return '0' <= c && c <= '9';
    }

public:
    /**
     * @param s: an expression includes numbers, letters and brackets
     * @return: a string
     */
    string expressionExpand(string &s) {
        int len = s.size();
        if(len == 0) return "";
        stack<string> stack;
        string result;
        for(int k = 0; k < len; ++k) {
            char c = s[k];
            if(c != ']') {
                stack.push(s.substr(k, 1));
                continue;
            }

            string content;
            while(!s.empty() && stack.top() != "[") {
                content = stack.top() + content;
                stack.pop();
            }

            stack.pop();

            string digit;
            while(!stack.empty() && isNumeric(stack.top()[0])) {
                digit = stack.top() + digit;
                stack.pop();
            }
            int repeat = stoi(digit);
            string expand;
            for(int i = 0; i < repeat; ++i) {
                expand += content;
            }
            stack.push(expand);
        }

        while(!stack.empty()) {
            result = stack.top() + result;
            stack.pop();
        }
        return result;
    }
};