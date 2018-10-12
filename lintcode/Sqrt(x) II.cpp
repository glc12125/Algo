class Solution {
public:
    /**
     * @param x: a double
     * @return: the square root of x
     */
    double sqrt(double x) {
        // write your code here
        double res = 1, pre = 0;
        while (abs(res - pre) > 1e-6) {
            pre = res;
            res = (res + x / res) / 2;
        }
        return res;
    }
};

// Using binary search
class Solution {
public:
    /**
     * @param x: a double
     * @return: the square root of x
     */
    double sqrt(double x) {
        if(x == 0 || x == 1) return x;

        double left;
        double right;
        double eps = 1e-12;
        double mid;        
        if(x > 1) {
            left = 0;
            right = x;
        } else {
            left = x;
            right = 1.0;
        }
        while(left + eps < right) {
            mid = left + (right - left) / 2;
            double power2 = mid * mid;
            if(power2 + eps < x) left = mid;
            else right = mid;
        }
        return left;
    }
};