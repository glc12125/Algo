//
//  main.cpp
//  contains_duplicats_3.leetcode
//
//  Created by Liangchuan Gu on 10/12/2017.
//  Copyright © 2017 Liangchuan Gu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <unordered_map>
#include <climits>

struct bst
{
    int data;
    int leftIdx;
    int rightIdx;
};

void MakeNode(std::vector<bst> &v1, int aData)
{
    struct bst b1 = { aData, -1, -1 };
    v1.push_back(b1);
}

void setleft(std::vector <bst>&v1, int currIndex, int aData)
{
    auto leftIndex = v1.size();
    v1[currIndex].leftIdx = leftIndex;
    struct bst b1 = { aData, -1, -1 };
    v1.push_back(b1);
}

void setright(std::vector<bst> &v1, int currIndex, int aData)
{
    auto rightIndex = v1.size();
    v1[currIndex].rightIdx = rightIndex;
    struct bst b1 = { aData, -1, -1 };
    v1.push_back(b1);
}

void Insert(std::vector<bst> &v1, int aData)
{
    if(v1.size() == 0)
    {
        std::cout<<"Note is not made yet. MakeNode first..."<<std::endl;
        return;
    }
    unsigned int currentIdx = 0;
    while ( currentIdx < v1.size() )
    {
        if(aData <= v1[currentIdx].data)
        {
            if( v1[currentIdx].leftIdx == -1)
            {
                setleft(v1, currentIdx, aData);
                break;
            }
            else
                currentIdx = v1[currentIdx].leftIdx;
        }
        else
        {
            if(v1[currentIdx].rightIdx == -1)
            {
                setright(v1, currentIdx, aData);
                break;
            }
            else
                currentIdx = v1[currentIdx].rightIdx;
        }
    }
}

struct ValueIndex
{
    int value;
    int index;
};

void InTravSort(const std::vector <bst> &v1, int Idx, std::vector <ValueIndex> &records)
{
    if(v1[Idx].leftIdx != -1)
        InTravSort(v1,v1[Idx].leftIdx, records);
    //std::cout<<v1[Idx].data<<std::endl;
    records.push_back(ValueIndex{v1[Idx].data, Idx});
    if( v1[Idx].rightIdx != -1)
        InTravSort(v1, v1[Idx].rightIdx, records);
}

void InTrav(std::vector <bst> &v1, unsigned int Idx)
{
    if(v1[Idx].leftIdx != -1)
        InTrav(v1,v1[Idx].leftIdx );
    std::cout<<v1[Idx].data<<std::endl;
    if( v1[Idx].rightIdx != -1)
        InTrav(v1, v1[Idx].rightIdx);
}

void PreTrav(std::vector <bst> &v1, unsigned int Idx)
{
    std::cout<<v1[Idx].data<<std::endl;
    if(v1[Idx].leftIdx != -1)
        PreTrav(v1,v1[Idx].leftIdx );
    if( v1[Idx].rightIdx != -1)
        PreTrav(v1, v1[Idx].rightIdx);
}
void PostTrav(std::vector <bst> &v1, unsigned int Idx)
{
    if(v1[Idx].leftIdx != -1)
        PostTrav(v1,v1[Idx].leftIdx );
    if( v1[Idx].rightIdx != -1)
        PostTrav(v1, v1[Idx].rightIdx);
    std::cout<<v1[Idx].data<<std::endl;
}

class Solution {
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t) {
        size_t size_nums = nums.size();
        if(size_nums == 0 || size_nums == 1 || k < 0 || t < 0) return false;
        std::vector<bst> v1;
        MakeNode(v1, nums.at(0));
        for(unsigned int i = 1; i < size_nums; ++i)
        {
            Insert(v1, nums.at(i));
        }
        InTrav(v1, 0);
        
        std::vector <ValueIndex> records;
        InTravSort(v1, 0, records);
        
        for (unsigned int i = 0; i < size_nums - 1; ++i)
        {
            for(unsigned int j = i + 1; j < size_nums; ++j)
            {
                auto left = records.at(i);
                auto right = records.at(j);
                if(std::abs((long long)left.value - (long long)right.value) <= t){
                    if(std::abs(left.index - right.index) <= k)
                    {
                        return true;
                    } else {
                        continue;
                    }
                } else {
                    break;
                }
            }
        }
        return false;
    }
    
    bool containsNearbyAlmostDuplicate1(std::vector<int>& nums, int k, int t) {
        if (nums.size() < 2 || k < 1 || t < 0) return false;
        std::set<long> window; // set is ordered automatically
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) window.erase(nums[i-k-1]); // keep the set contains nums i j at most k
            // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
            auto pos = window.lower_bound((long)nums[i] - t); // x-nums[i] >= -t ==> x >= nums[i]-t
            // x - nums[i] <= t ==> |x - nums[i]| <= t
            if (pos != window.end() && *pos - nums[i] <= t) return true;
            window.insert((long)nums[i]);
        }
        return false;
    }
    
    bool containsNearbyAlmostDuplicate2(std::vector<int>& nums, int k, int t) {
    
        if(k < 1 || t < 0) return false;
        std::unordered_map<long, long> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            long mappedNum = (long) nums[i] - INT_MIN;
            long bucket = mappedNum / ((long)t + 1);
            if(m.count(bucket) ||
               (m.count(bucket-1) && mappedNum - m.at(bucket-1) <= t) ||
               (m.count(bucket+1) && m.at(bucket+1) - mappedNum <= t)){
                return true;
            }
            if(m.size() >= k) {
                long lastBucket = ((long) nums[i - k] - INT_MIN) / ((long) t + 1);
                m.erase(lastBucket);
            }
            m[bucket] = mappedNum;
        }
        
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    //std::vector<int> nums = {3, 2, 5, 8, 19, 20, 6};
    //std::vector<int> nums = {-1, -1};
    //std::vector<int> nums = {4, 1, 6, 3};
    //std::vector<int> nums = {10, 100, 11, 9};
    std::vector<int> nums = {1, 3, 1};
    //std::vector<int> nums = {4, 2};
    //std::vector<int> nums = {-1, 2147483647};
    //std::vector<int> nums = {2147483647, -2147483647};
    //std::vector<int> nums = {10,100,200,9,0,11};
    //std::vector<int> nums = {-3, 3};
    //std::vector<int> nums = {-2147483648, -2147483647};
    auto result = s.containsNearbyAlmostDuplicate2(nums, 2, 1);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
