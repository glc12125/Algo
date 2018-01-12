//
//  main.cpp
//  Count_of_Range_Sum.leetcode
//
//  Created by Liangchuan Gu on 26/12/2017.
//  Copyright © 2017 Liangchuan Gu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    int countRangeSum(std::vector<int>& nums, int lower, int upper) {
        if( nums.size() == 0 || lower > upper) return 0;
        return countRangeSumSub(nums, 0, nums.size() - 1, lower, upper);
    }
    
private:
    int countRangeSumSub(std::vector<int>& nums, int l, int r, int lower, int upper)
    {
        if(l == r) return nums[l] >= lower && nums[r] <= upper ? 1 : 0;
        
        int m = l + (r - l)/2;
        const int size = r - m;
        std::vector<long> arr;
        arr.reserve(size);
        long sum = 0;
        int count = 0;
        
        for (int i = m + 1; i <= r; i++)
        {
            sum += nums[i];
            arr.push_back(sum);
        }
        
        std::sort(arr.begin(), arr.begin() + size);
        sum = 0;
        
        for( int i = m; i >= l; --i)
        {
            sum += nums[i];
            count += findIndex(arr, upper - sum + 0.5) - findIndex(arr, lower -sum - 0.5);
        }
        
        return countRangeSumSub(nums, l, m, lower, upper) + countRangeSumSub(nums, m + 1, r, lower, upper) + count;
    }
    
    int findIndex(std::vector<long>& arr, double val)
    {
        int l = 0, r = arr.size() - 1, m = 0;
        
        while (l <= r)
        {
            m = l + (r - l) / 2;
            
            if(arr[m] <= val)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        
        return l;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> nums = {-2, 5, -1};
    Solution s;
    std::cout << "Result " << s.countRangeSum(nums, -2, 2) << "\n";
    return 0;
}
