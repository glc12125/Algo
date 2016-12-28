//
//  main.cpp
//  top_k_frequent.leetcode
//
//  Created by lgu41 on 12/28/16.
//  Copyright © 2016 lgu41. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
    typedef pair<int, int> Pair;
    typedef multimap<int, int> Frequency;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        if (nums.size() == 0) return result;
        map<int, int> container;
        for (int num : nums) ++container[num];
        Frequency frequencyContainer;
        for (auto itr : container) frequencyContainer.insert(Pair(itr.second, itr.first));
        int i = 0;
        for (Frequency::reverse_iterator itr = frequencyContainer.rbegin();
             itr != frequencyContainer.rend(); ++itr) {
            if (++i > k) break;
            result.push_back(itr->second);
        }
        
        return result;
    }
};

class Solution1 {

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        if (nums.size() == 0) return result;
        map<int, int> container;
        for (int num : nums) ++container[num];
        vector<vector<int> > buckets(nums.size());
        for (auto itr : container) buckets[itr.second-1].push_back(itr.first);
        
        int counter = 0;
        for (unsigned long i = buckets.size() - 1; i > 0 && counter < k; --i) {
            if (buckets[i].size()) {
                copy(buckets[i].begin(), buckets[i].end(), back_inserter(result));
                counter += buckets[i].size();
            }
        }
        
        return result;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution1 s;
    vector<int> a = {1};
    vector<int> result = s.topKFrequent(a, 1);
    
    for (int i : result)
        cout << i << " ";
    
    cout << endl;
    return 0;
}
