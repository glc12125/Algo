//
//  main.cpp
//  palindrome_pairs.leetcode
//
//  Created by lgu41 on 11/27/16.
//  Copyright © 2016 lgu41. All rights reserved.
//

#include <iostream>
#include <string>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
    unordered_map<string, int> strIndexMap;
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int> > result;
        
        if (words.size() == 0) return result;
        
        for (unsigned int i = 0; i < words.size(); ++i) {
            strIndexMap[words[i]] = i;
        }
        
        for(int i = 0; i < words.size(); i++)
        {
            string cur = words[i], t_str;
            reverse(cur.begin(), cur.end());
            int t=0;
            unsigned long len=cur.size();
            for(int l = 0; l <= len; l++)
            {
                if(isPalindrome(cur,0, l-1))
                {
                    t_str = cur.substr(l);
                    if(strIndexMap.count(t_str))
                    {
                        t = strIndexMap[t_str];
                        if((t!=i) && (len>=words[t].size())) //avoid duplicates;
                            result.push_back(vector<int>{i, t});
                    }
                }
                if(isPalindrome(cur, l, len-1))
                {
                    t_str = cur.substr(0, l);
                    if(strIndexMap.count(t_str))
                    {
                        t = strIndexMap[t_str];
                        if((t!=i) && (len>words[t].size())) //avoid duplicates;
                            result.push_back(vector<int>{t, i});
                    }
                }
            }
        }
        return result;
    }
private:
    bool isPalindrome(const string& str, int start, int end) {
        while(str[start] == str[end]) start++, end--;
        return start >= end;
    }
};

int main()
{
    std::string x("xxbbbbccccczzzzxxxx");
    x.erase(std::unique(x.begin(), x.end()), x.end());
    std::cout << x << "\n";
    
    vector<string> test = {"abcd","dcba","lls","s","sssll"};
    Solution s;
    for (auto pair : s.palindromePairs(test)) {
        cout << "(";
        for (auto item : pair) {
            cout << item << " ";
        }
        cout << ")\n";
    }
    cout << "\n";
    Solution s2;
    //["ab","ba","abc","cba"]
    vector<string> test2 = {"ab","ba","abc","cba"};
    for (auto pair : s2.palindromePairs(test2)) {
        cout << "(";
        for (auto item : pair) {
            cout << item << " ";
        }
        cout << ")\n";
    }
}
