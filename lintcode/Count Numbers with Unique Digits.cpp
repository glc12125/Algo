class Solution {
private:
    int dfs(int n) {
        if(n == 0) return 0;
        if(n == 1) return 10;

        int prod = 1;
        int multiplier = 9;

        for(int i = 0; i < n; ++i) {
            if(i < 2) {
                prod *= multiplier;
            } else {
                prod *= (--multiplier);
            }
        }

        return prod + dfs(n-1);
    }
public:
    /**
     * @param n: a non-negative integer
     * @return: number of numbers with unique digits
     */
    int countNumbersWithUniqueDigits(int n) {
        if(n > 10) n = 10;
        dfs(n);
    }
};

// Iterative
class Solution {
public:
    /**
     * @param n: a non-negative integer
     * @return: number of numbers with unique digits
     */
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        if (n > 10) {
            n = 10;
        }
        int ans = 1;
        int multiple = 9;
        for (int i = 1; i <= n; ++i) {
            if (i == 1) {
                ans += multiple;
            } else {
                multiple = multiple * (11-i);
                ans += multiple;
            }
        }
        return ans;
    }
};