//
//  main.cpp
//  search a 2D matrix
//
//  Created by Liangchuan Gu on 09/03/2018.
//  Copyright © 2018 Liangchuan Gu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix.at(0).size() == 0) return false;
        int m = matrix.size();
        int n = matrix.at(0).size();
        int left = 0;
        int right = m * n - 1;
        int mid = 0;
        while(left <= right) {
            mid = (left + right) / 2;
            int row = mid / n;
            int col = mid % n;
            auto value = matrix.at(row).at(col);
            if(value == target) return true;
            else if (value < target) left = mid + 1;
            else right = mid - 1;
        }
        
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
