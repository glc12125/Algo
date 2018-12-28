//DP, Time O(N*M)
/*
Transision matrix

   ∅  b  d
∅  0 -1 -1
d  1 -1 -1
b  2  1 -1
d  3  1  1
*/
class Solution {
public:
    /**
     * @param S: a string
     * @param T: a string
     * @return: the minimum substring of S
     */
    string minWindow(string &S, string &T) {
        int m = S.size(), n = T.size(), start = -1, minLen = INT_MAX;
        // dp[i][j] means the starting position of the matched chars between
        // substrings before i in S and j in T.
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        for (int i = 0; i <= m; ++i) dp[i][0] = i;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= min(i, n); ++j) {
                /*
                    Transision matrix

                       ∅  b  d (T)
                    ∅  0 -1 -1
                    d  1 -1 -1
                    b  2  1 -1
                    d  3  1  1
                   (S)
                */
                dp[i][j] = (S[i - 1] == T[j - 1]) ? dp[i - 1][j - 1] : dp[i - 1][j];
            }
            // check if there is a full match of T for substring [0,i] in substring
            // and record the starting position
            if (dp[i][n] != -1) {
                int len = i - dp[i][n];
                if (minLen > len) {
                    minLen = len;
                    start = dp[i][n];
                }
            }
        }
        return (start != -1) ? S.substr(start, minLen) : "";
    }
};

// Two Pointers
class Solution {
public:
    /**
     * @param S: a string
     * @param T: a string
     * @return: the minimum substring of S
     */
    string minWindow(string &S, string &T) {
        int len = S.size();
        int tLen = T.size();
        if(tLen > len) return "";

        int maxLeft = -1;
        int minRight = -1;
        int minLen = INT_MAX;
        int index = 0;
        int max = len - tLen;
        while(index <= max) {
            int tIndex = 0;
            int left = -1;
            int right = -1;
            for(int i = index; i < len; ++i) {
                if(S[i] == T[tIndex]) {++tIndex;}
                if(left == -1 && tIndex == 1) {
                    left = i;
                    index = left + 1;
                }
                if(tIndex == tLen) {
                    right = i + 1;
                    break;
                }
            }
            if(left == -1 || right == -1) {
                break;
            }
            if(right - left < minLen) {
                maxLeft = left;
                minRight = right;
                minLen = right - left;
            }
        }

        if(maxLeft == -1 || minRight == -1) {
            return "";
        } else {
            return S.substr(maxLeft, minRight - maxLeft);
        }
    }
};