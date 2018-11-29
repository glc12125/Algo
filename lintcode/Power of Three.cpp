class Solution {
public:
    /**
     * @param n: an integer
     * @return: if n is a power of three
     */
    bool isPowerOfThree(int n) {
        // Write your code here
        while(n > 1 && n % 3 == 0) n /= 3;

        return n == 1;

    }
};

class Solution {
public:
    /**
     * @param n: an integer
     * @return: if n is a power of three
     */
    bool isPowerOfThree(int n) {
        // Write your code here
        if(n<=0)
            return false;
        double x=log10(n)/log10(3);
        if(x==(int)x)
            return true; 
        return false;
    }
};