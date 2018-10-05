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