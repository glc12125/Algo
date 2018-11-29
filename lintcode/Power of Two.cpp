class Solution {
public:
    /**
     * @param n: an integer
     * @return: if n is a power of two
     */
    bool isPowerOfTwo(int n) {
        return (n & (n-1)) == 0 && n > 0;
    }
};