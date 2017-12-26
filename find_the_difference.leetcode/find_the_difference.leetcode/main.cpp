//
//  main.cpp
//  find_the_difference.leetcode
//
//  Created by lgu41 on 12/12/16.
//  Copyright © 2016 lgu41. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution1 {
public:
    char findTheDifference(string s, string t) {
        int freqMap[26] = {0};
        char result = '\0';
        for (auto c : s) ++freqMap[c - 'a'];
        for (auto c : t) if ((--freqMap[c - 'a']) < 0 ) result = c;
        return result;
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        char r=0;
        for(char c : s + t) r ^=c;
        return r;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
