//
//  main.cpp
//  leetcode.4sum
//
//  Created by lgu41 on 11/18/16.
//  Copyright © 2016 lgu41. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef vector<pair<int, int> > PairVec;
typedef unordered_map<int, PairVec> PairMap;

class Solution {
private:
    PairMap pairMap;
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unsigned long count = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (unsigned int i = 0; i < count; ++i) {
            for (unsigned int j = i + 1; j < count; ++j) {
                int sum = nums.at(i) + nums.at(j);
                PairMap::iterator itr = pairMap.find(sum);
                if (itr == pairMap.end()) {
                    PairVec vec;
                    vec.push_back(pair<int, int>(i, j));
                    pairMap.insert(pair<int, PairVec>(nums[i] + nums[j], vec));
                } else {
                    itr->second.push_back(pair<int, int>(i, j));
                }
                
            }
        }
        
        for (unsigned int i = 0; i < count; ++i) {
            if(i>0 && nums[i] == nums[i-1]) continue;
            for (unsigned int j = i + 1; j < count; ++j) {
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                int sum2 = target - nums[i] - nums[j];
                if (pairMap.count(sum2)) {
                    for(PairVec::iterator pvItr = pairMap[sum2].begin(); pvItr != pairMap[sum2].end(); ++pvItr) {
                        unsigned int k = pvItr->first;
                        unsigned int l = pvItr->second;
                        if (k > j) {
                            if(!result.empty() && nums[i]==result.back()[0] && nums[j]==result.back()[1]
                               && nums[k]==result.back()[2] && nums[l] == result.back()[3]){
                                continue; //if the obtained 4 elements are the same as previous one continue to next
                            }
                            vector<int> solution = {nums[i], nums[j], nums[k], nums[l]};
                            result.push_back(solution);
                        }
                    }
                }
            }
        }
        
        return result;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
