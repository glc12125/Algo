class Solution {
public:
    /**
     * @param A: the given number
     * @param B: another number
     * @return: the last digit of B! / A!
     */
    int computeLastDigit(long long A, long long B) {
        if(B - A >= 10) return 0;

        int lastDigit = 1;
        for(long long i = A + 1; i <= B; ++i) {
            lastDigit *= (i % 10);
            lastDigit %= 10;
        }
        return lastDigit;
    }
};