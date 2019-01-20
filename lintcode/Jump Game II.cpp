// Time O(N^2), space O(N)
class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: An integer
     */
    int jump(vector<int> &A) {
        int len = A.size();
        if(len == 0) return 0;

        vector<int> dp(len, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i < len; ++i) {
            dp[i] = INT_MAX;
            for(int j = 0; j < i; ++j) {
                if(dp[j] != INT_MAX && A[j] >= i - j) {
                    dp[i] = std::min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[len-1];
    }
};

// Greedy time O(N), space O(1)
class Solution {
public:
    int jump(vector<int> A) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = A.size();
        int minstep = 0;
        int ldist = 0;
        int hdist = 0;
        if (n == 1) return 0;
        while(ldist <= hdist) {
            ++minstep;
            int lasthdist = hdist;
            for(int i = ldist; i <= lasthdist; ++i) {
                int possibledist = i + A[i];
                if (possibledist >= n-1)
                    return minstep;
                if (possibledist > hdist) {
                    hdist = possibledist;
                }
            }
            ldist = lasthdist + 1;
        }
        return 0;
    }
};