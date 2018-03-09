//
//  main.cpp
//  search insert
//
//  Created by Liangchuan Gu on 09/03/2018.
//  Copyright © 2018 Liangchuan Gu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto count = nums.size();
        if(count == 0) return 0;
        
        int left = 0;
        int right = count - 1;
        int mid;
        while(left <= right) {
            mid = (right + left) / 2;
            if (nums.at(mid) == target) return mid;
            else if (nums.at(mid) < target) left = mid + 1;
            else { right = mid - 1; }
        }
        
        return left;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
