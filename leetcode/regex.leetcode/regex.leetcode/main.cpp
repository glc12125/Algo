//
//  main.cpp
//  regex.leetcode
//
//  Created by Liangchuan Gu on 11/7/16.
//  Copyright © 2016 Liangchuan Gu. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    
    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }
        // Assuming there is at least one char before *
        if ('*' == p[1]) {
            // x* matches empty string or at least one character: x* -> xx*
            // *s is to ensure s is non-empty
            return (isMatch(s, p.substr(2)) ||
                    (!s.empty() &&
                     (s[0] == p[0] || '.' == p[0]) &&
                     isMatch(s.substr(1), p)));
        }
        else
            return !s.empty() &&
            (s[0] == p[0] || '.' == p[0]) &&
            isMatch(s.substr(1), p.substr(1));
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution s;
    std::cout << "result of aa vs a is: " << s.isMatch("aa", "a") << std::endl;
    std::cout << "result of aa vs aa is: " << s.isMatch("aa", "aa") << std::endl;
    std::cout << "result of aaa vs aa is: " << s.isMatch("aaa", "aa") << std::endl;
    std::cout << "result of aa vs a* is: " << s.isMatch("aa", "a*") << std::endl;
    std::cout << "result of aaa vs .* is: " << s.isMatch("aa", ".*") << std::endl;
    std::cout << "result of ab vs .* is: " << s.isMatch("ab", ".*") << std::endl;
    std::cout << "result of aab vs c*a*b* is: " << s.isMatch("aab", "c*a*b*") << std::endl;
    std::cout << "result of aaa vs a*a is: " << s.isMatch("aaa", "a*a") << std::endl;
    std::cout << "result of aaa vs a*aa is: " << s.isMatch("aaa", "a*aa") << std::endl;
    std::cout << "result of abcd vs d* is: " << s.isMatch("abcd", "d*") << std::endl;
    std::cout << "result of ab vs .*c is: " << s.isMatch("ab", ".*c") << std::endl;
    std::cout << "result of a vs ab* is: " << s.isMatch("a", "ab*") << std::endl;
    std::cout << "result of bbbba vs .*a*a is: " << s.isMatch("bbbba", ".*a*a") << std::endl;
    return 0;
}
