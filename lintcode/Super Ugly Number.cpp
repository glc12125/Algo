class Solution {
private:
    bool checkSuperUgly(int num, const unordered_set<int>& primeSet) {
        for(int i = 2; i * i <= num; ++i) {
            while (num % i == 0) {
                if(primeSet.count(i) == 0){
                    return false;
                }
                num /= i;
            }
        }

        if(num != 1) {
            if(primeSet.count(num) == 0){
                return false;
            }
        }
        return true;
    }
public:
    /**
     * @param n: a positive integer
     * @param primes: the given prime list
     * @return: the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        if(n == 1) return 1;
        unordered_set<int> primeSet(primes.begin(), primes.end());

        int curr = 2;
        int nTh = curr;
        for(int i = 1; i < n;) {
            if(checkSuperUgly(curr, primeSet)) {
                ++i;
                nTh = curr;
            }
            ++curr;
        }
        return nTh;
    }
};

// Time O((N + k)logK)
class Solution {
public:
    /**
     * @param n: a positive integer
     * @param primes: the given prime list
     * @return: the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        int cur=1;
        set<int> buf(primes.begin(), primes.end());
        for(int i = 1; i < n; ++i)
        {
            auto itr = buf.begin();
            cur = *itr;
            buf.erase(itr);
            for(int p:primes)
            {
                long long next = (long long)p * cur;
                if(next > INT_MAX)
                    continue;
                buf.insert(next);
            }
        }
        return cur;
    }
};