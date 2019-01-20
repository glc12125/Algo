// Time O(N^2), space O(N)
class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A) {
        int len = A.size();
        if(len == 0) return false;

        vector<bool> dp(len);

        dp[0] = true;

        for(int i = 1; i < len; ++i) {
            dp[i] = false;
            for(int j = 0; j < i; ++j) {
                if(dp[j] && A[j] >= i - j) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[len - 1];
    }
};

// Time O(N), space O(1)
class Solution {
public:
    bool canJump(vector<int> A) {
        int tmpMax = 0;
        int n = A.size();
        for (int i = 0; i < n; i++) {
            if (i > tmpMax) return false;
            if (tmpMax < i + A[i])
                tmpMax = i + A[i];
        }
        return true;
    }
};