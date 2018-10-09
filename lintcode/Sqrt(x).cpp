class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        if(x == 0) return 0;
        long left = 1;
        long right = x;
        long mid;
        while(left + 1 < right) {
            mid = left + (right - left) / 2;
            if(mid * mid < x) left = mid;
            else right = mid;
        }
        
        if(right * right <= x) return right;
        if(left * left <= x) return left;
        
    }
};