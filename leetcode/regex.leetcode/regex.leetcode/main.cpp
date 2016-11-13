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
    bool isMatch(string s, string p, const char& prevS, const char& prevP) {
        if (s.size() == 0 && p.size() == 0) {
            return true;
        } else if (s.size() == 0 && p.size() == 1) {
            if (p.at(0) == '*') {
                return true;
            } else {
                if (prevP == '*' && prevS == p.at(0)) {
                    return isMatch(s, p.substr(1), prevS, p.at(0));
                } else {
                    return false;
                }
            }
        } else if (s.size() == 0 && p.size() > 1) {
            if (p.at(0) != '*') {
                if (prevP == '*' && prevS == p.at(0)) {
                    return isMatch(s, p.substr(1), prevS, p.at(0));
                } else {
                    return false;
                }
            } else {
                return isMatch(s, p.substr(1), prevS, '*');
            }
        } else if (s.size() > 0 && p.size() == 0){
            return false;
        } else {
        
        if(p.at(0) == '*') {
            if (prevP == '.') {
                return isMatch(s.substr(1), p, s.at(0), prevP);
            } else {
                if (prevS != s.at(0)) {
                    return isMatch(s, p.substr(1), prevS, '*');
                } else if (prevS == s.at(0) && prevP == prevS){
                    return isMatch(s.substr(1), p, s.at(0), prevP);
                } else {
                    return isMatch(s, p.substr(1), prevS, p.at(0));
                }
            }
        } else if (p.at(0) == '.'){
            return isMatch(s.substr(1), p.substr(1), s.at(0), p.at(0));
        } else {
            if (s.at(0) == p.at(0)) {
                return isMatch(s.substr(1), p.substr(1), s.at(0), p.at(0));
            } else {
                if (p.size() > 1) {
                    return isMatch(s.substr(1), p.substr(1), s.at(0), p.at(0));
                } else {
                    return false;
                }
            }
        }
        }
        
    }
    
    bool isMatch(string s, string p) {
            return isMatch(s, p, '\0', '\0');
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
    return 0;
}
