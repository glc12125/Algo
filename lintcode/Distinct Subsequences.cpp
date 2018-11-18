class Solution {
public:
    /*
     * @param : A string
     * @param : A string
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string S, string T) {
        int len1 = S.size();
        int len2 = T.size();

        if(len1 < len2) return 0 ;
        vector<vector<int> > dp(2, vector<int>(len2 + 1, 0));

        for(int i = 0; i <= len1; ++i) {
            for(int j = 0; j <= len2; ++j) {
                if(i == 0 && j == 0) {
                    dp[i%2][j] = 1;
                    continue;
                }

                if(i == 0) {
                    dp[i%2][j] = 0;
                    continue;
                }

                if(j == 0) {
                    dp[i%2][j] = 1;
                    continue;
                }

                if(S[i-1] == T[j-1]) {
                    dp[i%2][j] = dp[(i-1)%2][j-1] + dp[(i-1)%2][j];
                } else {
                    dp[i%2][j] = dp[(i-1)%2][j];
                }
            }
        }

        return dp[len1%2][len2];
    }
};