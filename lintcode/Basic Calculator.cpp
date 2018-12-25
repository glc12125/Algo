class Solution {
private:
    bool isDigit(char c) {
        return '0' <= c && c <= '9';
    }

    bool isOperator(char c) {
        return c == '-' || c == '+';
    }

    struct Element{
        /*
         0 : (, 1 : ), 2: +/-, 3: number
        */
        int m_type;
        string m_content;
        Element() = default;
        Element(const string& content, int type) :
                 m_type(type), m_content(content){ }
    };

    int calculateFromStack(stack<Element>& currentEquation) {
        int result = 0;
        int currentNum = 0;
        char lastSign = ' ';
        while(!currentEquation.empty()) {
            if(currentEquation.top().m_type == 3) {
                currentNum = stoi(currentEquation.top().m_content);
            } else if (currentEquation.top().m_type == 2) {
                if(lastSign == ' ') {
                    result = currentNum;
                } else {
                    result = (lastSign == '+' ? result + currentNum : result - currentNum);
                }
                lastSign = currentEquation.top().m_content[0];
            }
            currentEquation.pop();
        }
        if(lastSign == ' ') {
            result = currentNum;
        } else {
            result = (lastSign == '+' ? result + currentNum : result - currentNum);
        }
        return result;
    }
public:
    /**
     * @param s: the given expression
     * @return: the result of expression
     */
    int calculate(string &s) {
        int len = s.size();
        if(len == 0) return 0;

        stack<Element> parsedEquation;
        stack<Element> parsingEquation;
        int index = 0;
        while(index < len) {
            if(s[index] == '(') {
                parsedEquation.emplace(Element(string(1, '('), 0));
                ++index;
            } else if (s[index] == ' ') {
                ++index;
            } else if (s[index] == ')') {
                ++index;
                while(parsedEquation.top().m_type != 0) {
                    parsingEquation.emplace(parsedEquation.top());
                    parsedEquation.pop();
                }
                parsedEquation.pop();
                parsedEquation.emplace(Element(to_string(calculateFromStack(parsingEquation)), 3));
            } else if (isDigit(s[index])){
                string digitString(1, s[index++]);
                while(isDigit(s[index])) {
                    digitString += s[index++];
                }
                parsedEquation.emplace(Element(digitString, 3));
            } else if(isOperator(s[index])){
                parsedEquation.emplace(Element(string(1, s[index++]), 2));
            }
        }

        while(!parsedEquation.empty()) {
            parsingEquation.emplace(parsedEquation.top());
            parsedEquation.pop();
        }
        return calculateFromStack(parsingEquation);
    }
};