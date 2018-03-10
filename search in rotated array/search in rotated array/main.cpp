//
//  main.cpp
//  search in rotated array
//
//  Created by Liangchuan Gu on 09/03/2018.
//  Copyright © 2018 Liangchuan Gu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int count = nums.size();
        if (count == 0) return -1;
        int left = 0;
        int right = count - 1;
        
        bool leftMove = false;
        while( left < right) {
            int mid = (left + right) / 2;
            std::cout << "left: " << left << ", right: " << right << "\n";
            std::cout << "mid: " << mid << "\n";
            if (nums.at(mid) < nums.at(left)) {
                right = mid - 1;
                leftMove = false;
            }
            else if (nums.at(mid) > nums.at(right)) {
                left = mid + 1;
                leftMove = true;
            }
            else break;
        }
        
        int pivot = leftMove ? left - 1 : right;
        std::cout << "pivot found: " << pivot << "\n";
        int offset = (pivot + 1) % count;
        left = 0;
        right = count - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            std::cout << "mid: " << mid << "\n";
            int offsetMid = offsetIndex(mid, count, offset);
            std::cout << "offsetMid: " << offsetMid << "\n";
            if(nums.at(offsetMid) == target) return offsetMid;
            if (nums.at(offsetMid) < target) left = mid + 1;
            else right = mid - 1;
        }
        
        return -1;
    }
private:
    int offsetIndex(int originalIndex, int count, int offset) {
        return offset ? (originalIndex + offset) % count : originalIndex;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> sample = {4,5,6,7,8,1,2,3};
    std::cout << "search 8 in {3, 5, 1}}: " << s.search(sample, 8) << "\n";
    return 0;
}
