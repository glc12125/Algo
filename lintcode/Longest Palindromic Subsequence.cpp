class Solution {
public:
    /**
     * @param s: the maximum length of s is 1000
     * @return: the longest palindromic subsequence's length
     */
    int longestPalindromeSubseq(string &s) {
        int size = s.size();
        if(size == 0) return 0;
        int dp[size][size] = {0};
        for(int i = 0; i < size; ++i) {
            dp[i][i] = 1;
        }

        for(int i = size - 1; i > -1; --i) {
            for(int j = i + 1; j < size; ++j) {
                if(s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i+1][j-1];
                } else {
                    dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return dp[0][size-1];
    }
};

// Memoisation
class Solution {
private:
    void calc(const string& s, vector<vector<int>>& mem, int i, int j) {
        if(mem[i][j] != -1) return;

        if(i == j) {
            mem[i][j] = 1;
            return;
        }

        if(i + 1 ==j) {
            mem[i][j] = (s[i] == s[j] ? 2 : 1);
            return;
        }

        calc(s, mem, i + 1, j);
        calc(s, mem, i, j - 1);
        calc(s, mem, i + 1, j - 1);

        mem[i][j] = std::max(mem[i+1][j], mem[i][j-1]);
        if(s[i] == s[j]) mem[i][j] = std::max(mem[i][j], mem[i+1][j-1] + 2);
    }
public:
    /**
     * @param s: the maximum length of s is 1000
     * @return: the longest palindromic subsequence's length
     */
    int longestPalindromeSubseq(string &s) {
        int size = s.size();
        if(size == 0) return 0;
        vector<vector<int>> dp(size, vector<int>(size, -1));

        calc(s, dp, 0, size - 1);

        return dp[0][size-1];
    }
};