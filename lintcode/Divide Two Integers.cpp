class Solution {
public:
    /**
     * @param dividend: the dividend
     * @param divisor: the divisor
     * @return: the result
     */
    int divide(int dividend, int divisor) {
        if(divisor == 0) return 2147483647;
        if(dividend == 0) return 0;

        bool isNegative = false;
        long lDividend = dividend;
        long lDivisor = divisor;
        if(lDividend < 0) {
            isNegative = !isNegative;
            lDividend = -lDividend;
        }
        if(lDivisor < 0) {
            isNegative = !isNegative;
            lDivisor = -lDivisor;
        }
        if(lDivisor > lDividend) return 0;
        if(lDivisor == 1) {
            if(isNegative) return -lDividend;
            else {
                if(lDividend == (long)INT_MAX+1) return INT_MAX;
                else return lDividend;
            }
        }
        long maxDivisor = lDivisor;
        std::vector<int> divisors;
        while(maxDivisor <= lDividend){
            divisors.push_back(maxDivisor);
            maxDivisor += maxDivisor;
        }
        
        int counter = divisors.size();
        int result = 1;
        result <<= (counter - 1);
        maxDivisor -= divisors[counter - 1];
        for(int i = counter - 1; i > -1; --i) {
            while(maxDivisor + divisors[i] <= lDividend) {
                maxDivisor += divisors[i];
                result += (1 << i);
            }
        }
        
        return isNegative ? -result : result;
    }
};


// Without O(log_divisor(dividend)) space

public class Solution {
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    public int divide(int dividend, int divisor) {
        if (divisor == 0) {
             return dividend >= 0? Integer.MAX_VALUE : Integer.MIN_VALUE;
        }
        
        if (dividend == 0) {
            return 0;
        }
        
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }
        
        boolean isNegative = (dividend < 0 && divisor > 0) || 
                             (dividend > 0 && divisor < 0);
                             
        long a = Math.abs((long)dividend);
        long b = Math.abs((long)divisor);
        int result = 0;
        while(a >= b){
            int shift = 0;
            while(a >= (b << shift)){
                shift++;
            }
            a -= b << (shift - 1);
            result += 1 << (shift - 1);
        }
        return isNegative? -result: result;
    }
}