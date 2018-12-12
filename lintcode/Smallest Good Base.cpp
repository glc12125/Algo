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
        long long end = n / 2;
        while(start + 1 < end) {
            long long mid = start + (end - start) / 2;
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