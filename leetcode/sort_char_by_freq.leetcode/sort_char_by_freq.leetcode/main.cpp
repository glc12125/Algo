//
//  main.cpp
//  sort_char_by_freq.leetcode
//
//  Created by lgu41 on 12/3/16.
//  Copyright © 2016 lgu41. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

class Solution {
    unordered_map<char, int> freqMap;
    multimap<int, char> revFreqMap;
public:
    string frequencySort(string s) {
        if (s.size() == 0) return "";
        
        string result;
        for (unsigned int i = 0; i < s.size(); ++i){
            ++freqMap[s[i]];
        }
        for (unordered_map<char, int>::iterator it = freqMap.begin(); it != freqMap.end(); ++it) {
            revFreqMap.insert(pair<int, char>(it->second, it->first));
        }
        for (multimap<int, char>::reverse_iterator rIt = revFreqMap.rbegin(); rIt != revFreqMap.rend(); ++rIt) {
            for (int i = 0; i < rIt->first; ++i) {
                result += rIt->second;
            }
        }
        
        return result;
    }
};

class Solution1 {
public:
    string frequencySort(string s) {
        if (s.size() == 0) return "";
        unordered_map<char, int> freqMap;
        vector<string> bucket(s.size()+1, "");
        
        string result;
        for (char c : s){
            ++freqMap[c];
        }
        
        for (auto p : freqMap) {
            int n = p.second;
            bucket[n].append(n, p.first);
        }
        for (unsigned long i = s.size(); i > 0; --i) {
            if(bucket[i].empty()) continue;
            result.append(bucket[i]);
        }
        
        return result;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
