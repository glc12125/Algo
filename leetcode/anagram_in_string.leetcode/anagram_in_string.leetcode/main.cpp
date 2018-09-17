//
//  main.cpp
//  anagram_in_string.leetcode
//
//  Created by lgu41 on 12/5/16.
//  Copyright © 2016 lgu41. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
    typedef unordered_map<char, int> Container;
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        Container freqMap(p.size());
        for (char c : p) {
            ++freqMap[c];
        }
        
        for (unsigned int i = 0; i < s.size() - p.size(); ++i) {
            Container tempMap = freqMap;
            unsigned int j = i;
            for (; j < i + p.size(); ++j) {
                Container::iterator itr = tempMap.find(s[j]);
                if(itr == tempMap.end()) break;
                if(--(itr->second) < 0) break;
            }
            if (j == i + p.size()) result.push_back(i);
        }
        
        return result;
    }
};

class Solution1 {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (p.size() > s.size()) return result;
        int table[26]{0};
        for (char c : p) ++table[c-'a'];
        
        int count = 0;
        unsigned int l = 0;
        for (unsigned int r = 0; r < s.size(); ++r) {
            if (r - l == p.size() && ++table[s[l++]-'a'] > 0) --count;
            if (table[s[r] - 'a']-- > 0 && ++count == p.size()) result.push_back(l);
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution1 s;
    vector<int> result = s.findAnagrams("cbaebabacd", "abc");
    for (auto i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
