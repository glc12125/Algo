//
//  main.cpp
//  lexicographical_nthe_smallest.leetcode
//
//  Created by lgu41 on 11/15/16.
//  Copyright © 2016 lgu41. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findKthNumber(int n, int k, int start = 0) {
        if(k > 0) {
            for(int i = (start==0)?1:0; i <= 9; i++) { // append 0-9 to the prefix
                int count = numbersBeginWith(n, 10*start+i);
                if(k <= count) // if k <= count, the answer is begin with the prefix
                    return findKthNumber(n, k-1, 10*start+i);
                k -= count; // if the answer does not begin with the prefix, remove all the numbers begin with this prefix
            }
        }
        return start;
    }
    
    // return how many numbers are begin with the prefix and in the range of N
    int numbersBeginWith(int n, long long prefix)
    {
        long long fac = 1;
        int count = 0;
        for(int digit = 1; digit <= 9; digit++) {
            long long min = prefix*fac;
            long long max = prefix*fac+fac-1;
            if(n < min)
                break;
            else if(min <= n && n <= max) {
                count += (n-min+1);
                break;
            }
            else
                count += fac;
            fac *= 10;
        }
        return count;
    }
};

class Solution1 {
public:
    int findKthNumber(int n, int k)
    {
        int result = 1;
        for(--k; k > 0; )
        {
            // calculate #|{result, result*, result**, result***, ...}|
            int count = 0;
            for (long long first = static_cast<long long>(result), last = first + 1;
                 first <= n; // the interval is not empty
                 first *= 10, last *= 10) // increase a digit
            {
                // valid interval = [first, last) union [first, n]
                count += static_cast<int>((min(n + 1LL, last) - first)); // add the length of interval
            }
            
            if (k >= count)
            {   // skip {result, result*, result**, result***, ...}
                // increase the current prefix
                ++result;
                k -= count;
            }
            else
            {   // not able to skip all of {result, result*, result**, result***, ...}
                // search more detailedly
                result *= 10;
                --k;
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    std::cout << "(1, 1): " << s.findKthNumber(1, 1) << std::endl;
    return 0;
}
