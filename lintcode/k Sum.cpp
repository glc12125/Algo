// Time O(MKT), space O(KT)
class Solution {
public:
    /**
     * @param A: An integer array
     * @param k: A positive integer (k <= length(A))
     * @param target: An integer
     * @return: An integera
     */
    int kSum(vector<int> &A, int K, int T) {
        int n = A.size();
        vector<vector<vector<int>>> dp(2,vector<vector<int>>(K+1, vector<int>(T+1)));

        for(int j = 0; j <=K; ++j) {
            for(int k = 0; k <=T; ++k) {
                dp[0][j][k] = 0;
            }
        }

        dp[0][0][0] = 1;

        for(int i = 1; i <= n ;++i) {
            // for first i numbers
            for(int j = 0 ;j <= K; ++j) {
                // choose exactly j numbers
                for(int k = 0; k <= T; ++k) {
                    // such that the sum is k
                    // if i - 1 is not selected
                    dp[i%2][j][k] = dp[(i-1)%2][j][k];

                    // A[i-1] is selected
                    if(j > 0 && k >=A[i-1]) {
                        dp[i%2][j][k] += dp[(i-1)%2][j-1][k-A[i-1]];
                    }
                }
            }
        }
        return dp[n%2][K][T];
    }
};