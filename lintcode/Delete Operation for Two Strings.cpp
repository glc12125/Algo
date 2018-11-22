class Solution {
public:
    /**
     * @param word1: a string
     * @param word2: a string
     * @return: return a integer
     */
    int minDistance(string &word1, string &word2) {
        int len1 = word1.size();
        int len2 = word2.size();

        vector<vector<int>> dp(2, vector<int>(len2 + 1, 0));
        for(int i = 1; i <= len1; ++i) {
            for(int j = 1; j <= len2; ++j) {
                if(i == 0 || j == 0) {
                    dp[i%2][j] = 0;
                    continue;
                }
                dp[i%2][j] = std::max(dp[(i-1)%2][j], dp[i%2][j-1]);
                if(word1[i-1] == word2[j-1]) {
                    dp[i%2][j] = std::max(dp[i%2][j], dp[(i-1)%2][j-1] + 1);
                }
            }
        }
        return len1 + len2 - 2*dp[len1%2][len2];
    }
};