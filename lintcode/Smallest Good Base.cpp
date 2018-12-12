// Time O(NlogN), it iterates through all possible bases from small to big
class Solution {
private:
    bool checkBase(long long base, long long n) {
        long long current = 1;
        while(current < n) {
            current = current * base + 1;
        }
        return current == n;
    }
public:
    /**
     * @param n: a string
     * @return: return a string
     */
    string smallestGoodBase(string &n) {
        long long llN = stoll(n);
        for(long long i = 2; i < llN; ++i) {
            if(checkBase(i, llN)) {
                return to_string(i);
            }
        }
        return to_string(llN - 1);
    }
};

//Binary search by the answer, time O(logN*logN)
class Solution {
private:
    long long baseToDecimal(long long base, int len) {
        long long current = 1;
        for(int i = 1; i < len; ++i) {
            current = current * base + 1;
        }
        return current;
    }

    long long findBase(int len, long long n) {
        long long start = 0;
        long long end = (n >> 1);
        while(start + 1 < end) {
            long long mid = start + ((end - start) >> 1);
            auto result = baseToDecimal(mid, len);
            if(result < n) start = mid;
            else end = mid;
        }
        if(baseToDecimal(start, len) == n) return start;
        if(baseToDecimal(end, len) == n) return end;
        return -1;
    }
public:
    /**
     * @param n: a string
     * @return: return a string
     */
    string smallestGoodBase(string &n) {
        long long llN = stoll(n);
        int len = (int)log2(llN) + 1;
        while(len > 2) {
            auto found = findBase(len, llN);
            if(found != -1) {
                return to_string(found);
            }
            --len;
        }

        return to_string(llN - 1);
    }
};

// Mathematics
/*
Let's say base is our final good base, k is the number 1 after base conversion,
We then have the following:
base^(k-1) + base^(k-2) + … + base^1 + base^0 = N ------- [1]
base^k + base^(k-1) + … + base^2 + base^1 = N * base ------- [1]'
[1]' - [1], we can have:
base^k - base^0 = (base - 1) * N
N = (base^k - 1) / (base - 1) ----- [2]
From [1] we can also have the following equation:
base ^ (k-1) < N < (base+1) ^ (k-1) … the upper bound is not obvious, but if you
take 2 as the base, it will be obvious. Get root of (k-1) on both sides, we get:
base < (k-1)-th root of N < base + 1 ----[3]
We can iterate the length of the final good base to find answer according to [2] and [3]
*/
class Solution {
public:
    /**
     * @param n: a string
     * @return: return a string
     */
    string smallestGoodBase(string &n) {
        long long llN = stoll(n);
        int len = (int)log2(llN) + 1;
        while(len > 2) {
            // from equation [3], we havve
            long long base = (long long)pow(llN, (1.0/(len-1)));
            // from equation [2], we have
            if(llN * (base - 1) == (long long)pow(base, len) - 1) {
                return to_string(base);
            }
            --len;
        }

        return to_string(llN - 1);
    }
};