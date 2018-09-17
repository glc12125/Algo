#include <iostream>

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0) {
            return false;
        }

        while (!(n & 1)) {
            n = n >> 1;
        }

        if (!(n ^ 1)) {
            return true;
        } else {
            return false;
        }
    }
};
int main()
{
    Solution s;

    s.isPowerOfTwo(3);
}
