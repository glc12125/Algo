class Solution {
public:
    /**
     * @param s: a message being encoded
     * @return: an integer
     */
    int numDecodings(string &s) {
        int n = s.size();
        if(n == 0) return 0;

        const int MOD = 1e9 + 7;
        vector<long> f(n + 1);
        f[0] = 1;

        for(int i = 1; i <= n; ++i) {
            auto curr = s[i-1];
            if(curr != '*') {
                f[i] = 0;
                if(curr != '0') {
                    f[i] = (f[i] + f[i-1]) % MOD;
                }

                if(i > 1) {
                    auto prev = s[i-2];
                    if(prev != '*') {
                        if((prev == '1' || (prev == '2' && curr <= '6')) ) {
                            f[i] = (f[i] + f[i-2]) % MOD;
                        }
                    } else {
                        if(curr >= '7') {
                            f[i] = (f[i] + f[i-2]) % MOD;
                        } else {
                            f[i] = (f[i] + f[i-2] * 2) % MOD;
                        }
                    }
                }
            } else {
                f[i] = 0;
                f[i] = (f[i] + f[i-1] * 9L) % MOD;

                if(i > 1) {
                    auto prev = s[i-2];
                    if(prev != '*') {
                        if(prev == '1') {
                            f[i] = (f[i] + f[i-2] * 9) % MOD;
                        } else if( prev == '2'){
                            f[i] = (f[i] + f[i-2] * 6) % MOD;
                        }
                    } else {
                        f[i] = (f[i] + f[i-2] * 15) % MOD;
                    }
                }
            }
        }

        return f[n] % MOD;
    }
};