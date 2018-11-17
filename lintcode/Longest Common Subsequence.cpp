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

// With path printing
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
        vector<vector<int> > pi(len1 + 1, vector<int>(len2 + 1, 0));

        for(int i = 1; i <= len1; ++i) {
            for(int j = 1; j <=len2; ++j) {
                if(A[i-1] == B[j-1]) {
                    dp[i][j] = std::max(dp[i-1][j-1] + 1, std::max(dp[i-1][j], dp[i][j-1]));
                    if(dp[i][j] == dp[i-1][j-1] + 1) {
                        pi[i][j] = 2;
                    }
                } else {
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                    if(dp[i][j] == dp[i-1][j]) {
                        pi[i][j] = 0;
                    } else {
                        pi[i][j] = 1;
                    }
                }
            }
        }

        vector<char> res(dp[len1][len2]);
        int i = len1;
        int j = len2;
        int p = dp[len1][len2] - 1;
        while(i > 0 && j > 0) {
            if(pi[i][j] == 0) {--i;}
            else {
                if(pi[i][j] == 1) {
                    --j;
                } else {
                    res[p] = A[i-1];
                    --p;
                    --i;
                    --j;
                }
            }
        }

        for(auto i : res) std::cout << i << " ";

        return dp[len1][len2];
    }
};