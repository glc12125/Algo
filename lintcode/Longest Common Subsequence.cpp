class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
    int longestCommonSubsequence(string &A, string &B) {
        int len1 = A.size();
        int len2 = B.size();

        vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));

        for(int i = 1; i <= len1; ++i) {
            for(int j = 1; j <=len2; ++j) {
                if(A[i-1] == B[j-1]) {
                    dp[i][j] = std::max(dp[i-1][j-1] + 1, std::max(dp[i-1][j], dp[i][j-1]));
                } else {
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[len1][len2];
    }
};