#include <cstdlib>
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0) {
            return false;
        }
        int length = 0;
        for (int d = x; d > 0; d /= 10) {
            ++length;
        }
        if (length == 1) {
            return true;
        }
        int *digits = (int *)malloc(length * sizeof(int));
        int i = 0;
        for (int d = x; d > 0; d /= 10) {
            digits[i] = d % 10;
            ++i;
        }

        for (i = 0; i < length / 2; ++i) {
            if (digits[i] != digits[length - 1 - i]) {
                delete [] digits;
                return false;
            }
        }

        delete [] digits;

        return true;
    }
};
