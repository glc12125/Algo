// DP time O(S*T), space O(T)
class Solution {
public:
    /**
     * @param s: string S
     * @param t: string T
     * @return: whether S can convert to T
     */
    bool canConvert(string &s, string &t) {
        int lenS = s.size();
        int lenT = t.size();

        vector<vector<bool>> dp(2, vector<bool>(lenT + 1, false));
        dp[0][0] = true;
        dp[1][0] = true;

        for(int j = 1; j <= lenT; ++j) {
            dp[0][j] = false;
        }

        for(int i = 1; i <= lenS; ++i) {
            for(int j = 1; j <= lenT; ++j) {
                if(i < j) {
                    dp[i%2][j] = false;
                    continue;
                }
                dp[i%2][j] = false;
                if(s[i-1] == t[j-1]) {
                    dp[i%2][j] = dp[(i-1)%2][j-1];
                }
                else {
                    dp[i%2][j] = dp[(i-1)%2][j];
                }
            }
        }

        return dp[lenS%2][lenT];
    }
};

// time O(S)
class Solution {
public:
    /**
     * @param s: string S
     * @param t: string T
     * @return: whether S can convert to T
     */
    bool canConvert(string &s, string &t) {
        int lenS = s.size();
        int lenT = t.size();

        int j = 0;
        for(int i = 0; i < lenS; ++i) {
            if(s[i] == t[j]) {
                if(++j == lenT) break;
            }
        }

        return j == lenT;
    }
};