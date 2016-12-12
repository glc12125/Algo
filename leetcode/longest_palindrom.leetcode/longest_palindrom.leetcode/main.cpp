//
//  main.cpp
//  longest_palindrom.leetcode
//
//  Created by lgu41 on 12/12/16.
//  Copyright © 2016 lgu41. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution1 {
public:
    int longestPalindrome(string s) {
        if (s.empty()) return 0;
        if (s.size() == 1) return 1;
        int result = 0;
        bool hasSingleChar = false;
        int freqArray[58] = {0};
        for (auto c : s) ++freqArray[c-'A'];
        for (int i : freqArray) {
            if (i%2 == 0) {
                result += i;
                continue;
            } else if (i > 2) {
                result += i-1;
            }
            hasSingleChar = true;
        }
        
        if (hasSingleChar) ++result;
        
        return result;
    }
};

class Solution {
public:
    int longestPalindrome(string s) {
        if (s.empty()) return 0;
        if (s.size() == 1) return 1;
        int result = 0;
        unordered_map<int, int> container;
        for (auto c : s) {
            int index = c - 'A';
            if (container[index]) {
                result += 2;
                container.erase(index);
            }
            else ++container[index];
        }
        
        return container.size() == 0 ? result : result + 1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
