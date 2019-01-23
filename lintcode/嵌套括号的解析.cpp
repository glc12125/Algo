#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> parse(const string& s, int& index) {
        int len = s.size();
        vector<string> answers;
        string current;
        while(index < len) {
            char currentChar = s[index];
            if (isComma(currentChar)) {
                ++index;
            } else if (currentChar == '{') {
                if(!current.empty()) {
                    if(answers.empty()) {
                        answers.push_back(current);
                    } else {
                        for(auto& answer : answers) {
                            answer += current;
                        }
                    }
                    current.clear();
                }
                ++index;
                vector<char> expanded = divideAndConquer(s, index);

                if(answers.empty()) {
                    for(const auto& c : expanded) {
                        answers.push_back(string(1, c));
                    }
                } else {
                    vector<string> newAnswer;
                    for(auto& answer : answers) {
                        for(const auto& c : expanded) {
                            newAnswer.push_back(answer + c);
                        }
                    }
                    answers = newAnswer;
                }
            }  else {
                current += currentChar;
                ++index;
            }
        }

        if(!current.empty()) {
            if(answers.empty()) {
                answers.push_back(current);
            } else {
                for(auto& answer : answers) {
                    answer += current;
                }
            }
        }

        return answers;
    }

    vector<char> divideAndConquer(const string& s, int& index) {
        int len = s.size();

        vector<char> answers;
        while(index < len) {
            char currentChar = s[index];
            if (isComma(currentChar)) {
                ++index;
            } else if (currentChar == '{') {
                ++index;
                vector<char> expanded = divideAndConquer(s, index);
                if(answers.empty()) {
                    answers = expanded;
                } else {
                    for(auto c : expanded) {
                        answers.push_back(c);
                    }
                }
            } else if (currentChar == '}') {
                ++index;
                return answers;
            } else {
                answers.push_back(currentChar);
                ++index;
            }
        }

        return answers;
    }
    bool isComma(char c) {
        return c == ',';
    }
public:
    /**
     * @param s: an expression includes numbers, letters and brackets
     * @return: a string
     */
    vector<string> expressionExpand(const string &s) {
        int len = s.size();
        if(len == 0) return {};
        int index = 0;
        return parse(s, index);
    }
};

void printAnswer(const vector<string>& result) {
    std::cout << "result:\n";

    for(const auto& answer: result) {
        std::cout << answer << ", ";
    }
    std::cout << "\n";
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    printAnswer(s.expressionExpand("b{c,f,g}a"));
    printAnswer(s.expressionExpand("ab{c,{d,e},f}g"));
    return 0;
}