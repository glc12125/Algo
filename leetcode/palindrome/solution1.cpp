class Solution
{
public:
    bool isPalindrome(int x)
    {
        int rev = 0;
        int n = x;
        while (n > 0) {
            int digit = n % 10;
            rev = rev * 10 + digit;
            n /= 10;
        }
        if (x == rev) {
            return true;
        } else {
            return false;
        }
    }
};
