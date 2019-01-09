// Time O(N), space O(N)
class Solution {
public:
    /**
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
    int numDecodings(string &s) {
        int n = s.size();
        if(n == 0) return 0;

        vector<int> f(n + 1);
        f[0] = 1;

        for(int i = 1; i < n + 1; ++i) {
            f[i] = 0;
            if(s[i-1] != '0') {
                f[i] += f[i-1];
            }

            if(i >= 2 && (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6'))) {
                f[i] += f[i-2];
            }
        }

        return f[n];
    }
};