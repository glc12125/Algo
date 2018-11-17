class Solution {
private:
    double EPSILON = std::numeric_limits<double>::epsilon();
public:
    /**
     * @param x: the base number
     * @param n: the power number
     * @return: the result
     */
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        if(n == 1) return x;
        if(x == 1) return 1;
        if(n == INT_MIN) return 0.0;
        if(n < 0) {
            x = 1/x;
            n = -n;
        }
        auto halfResult = myPow(x, n / 2);
        return n % 2 ? x * halfResult * halfResult : halfResult * halfResult;
    }
};

// Iterative
class Solution {
public:
    /*
     * @param x: the base number
     * @param n: the power number
     * @return: the result
     */
    double myPow(double x, int n) {
        bool isNegative = false;
        if (n < 0) {
            x = 1 / x;
            isNegative = true;
            n = - (n + 1); // handle integer overflow
        }
        double ans = 1, temp = x;
        while (n != 0) {
            if (n % 2 == 1) {
                ans *= temp;
            }
            temp *= temp;
            n /= 2;
        }

        if (isNegative) {
            ans *= x;
        }

        return ans;

    }
};