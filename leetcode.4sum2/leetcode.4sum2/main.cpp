//
//  main.cpp
//  leetcode.4sum2
//
//  Created by lgu41 on 11/16/16.
//  Copyright © 2016 lgu41. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
private:
    unordered_map<int, int> AB, CD;
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unsigned long count = A.size(); // All with the same size
        int totalNumber = 0;
        /*
         for (unsigned int i = 0; i < count; ++i) {
         int sum = A.at(i);
         for (unsigned int j = 0; j < count; ++j) {
         sum += B.at(j);
         for (unsigned int k = 0; k < count; ++k) {
         sum += C.at(k);
         for (unsigned int l = 0; l < count; ++l) {
         if ((sum + D.at(l)) == 0) {
         ++totalNumber;
         }
         }
         sum -= C.at(k);
         }
         sum -= B.at(j);
         }
         }*/
        for (unsigned int i = 0; i < count; ++i) {
            for (unsigned int j = 0; j < count; ++j) {
                ++AB[A.at(i) + B.at(j)];
                ++CD[C.at(i) + D.at(j)];
            }
        }
        
        for (unordered_map<int,int>::iterator i = AB.begin(); i != AB.end(); ++i) {
            totalNumber += i->second * CD[-i->first];
        }
        return totalNumber;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
