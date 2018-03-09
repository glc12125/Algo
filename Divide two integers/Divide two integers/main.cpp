//
//  main.cpp
//  Divide two integers
//
//  Created by Liangchuan Gu on 08/03/2018.
//  Copyright © 2018 Liangchuan Gu. All rights reserved.
//

#include <iostream>
#include <climits>

class Solution {
public:
    int divide(int dividend, int divisor){
        if(divisor == 0) return INT_MAX;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        bool negative = ((((dividend & (1 << 31)) == (1 << 31)) ^ ((divisor & (1 << 31)) == (1 << 31))) ? true : false);
        
        int result = 0;
        long dvd = labs(dividend);
        long dvs = labs(divisor);
        
        while (dvd >= dvs)
        {
            long temp = dvs;
            int times = 1;
            while(dvd >=(temp << 1))
            {
                temp <<= 1;
                times <<= 1;
            }
            dvd -= temp;
            result += times;
        }
        
        return (negative ? -result : result);
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    Solution s;
    std::cout << "-1021989372/-82778243: " << s.divide(-1021989372, -82778243) << "\n";
    return 0;
}
