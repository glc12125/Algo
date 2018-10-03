class Solution {
public:
    /**
     * @param a: A 32bit integer
     * @param b: A 32bit integer
     * @param n: A 32bit integer
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        if(a == 0) return 0;
        if(n == 0) return 1%b;
        if(n == 1) return a%b;
        
        if(n < 0) {
            a = 1/a;
            n = -n;
        }
        
        long long half = fastPower(a, b, n/2);
        if(n%2) {
            return ((half * half) % b * a ) % b;
        } else {
            return (half * half) % b;
        }
    }
};