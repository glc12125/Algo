// Time O(M*N), space O(M*N) -> O(N)
class Solution {
public:
    /**
     * @param s1: A string
     * @param s2: A string
     * @param s3: A string
     * @return: Determine whether s3 is formed by interleaving of s1 and s2
     */
    bool isInterleave(string &s1, string &s2, string &s3) {
        int m = s1.size();
        int n = s2.size();
        if(s3.size() != m + n) return false;

        vector<vector<bool>> dp(m + 1, vector<bool>(n+1));

        for(int i = 0; i <= m; ++i) {
            for(int j = 0; j <= n; ++j) {
                if(i == 0 && j == 0) {
                    dp[i][j] = true;
                    continue;
                }

                dp[i][j] = false;
                if(i > 0 && s3[i+j-1] == s1[i-1] && dp[i-1][j]) {
                    dp[i][j] = true;
                }
                if(j > 0 && s3[i+j-1] == s2[j-1] && dp[i][j-1]) {
                    dp[i][j] = true;
                }
            }
        }

        return dp[m][n];
    }
};