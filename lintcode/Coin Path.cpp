// DP, Time O(N^2), space O(N)
class Solution {
public:
    /**
     * @param A: a list of integer
     * @param B: an integer
     * @return: return a list of integer
     */
    vector<int> cheapestJump(vector<int> &A, int B) {
        int len = A.size();
        if(len == 1 && A[0] != -1) return {1};
        if(A[0] == -1 || A[len-1] == -1) return {};

        // means minimal cost, -1 means it cannot be reached
        // we iterate from back to front, because we need to print
        // the lexicographically smallest path. Then the dp array means
        // the ith position reachable with minimal cost
        vector<int> dp(len, INT_MAX);
        // initialization, where the destination(the starting position) should
        // be assigned with the cost from A
        vector<int> path(len, -1);
        dp[len-1] = A[len-1];
        for(int i = len - 2; i >= 0; --i) {
            if(A[i] == -1) {
                continue;
            }

            int max = std::min(i + B, len - 1);
            for(int j = i + 1; j <= max; ++j) {
                if(dp[j] == INT_MAX) {
                    continue;
                }
                if(A[i] + dp[j] < dp[i]) {
                    dp[i] = A[i] + dp[j];
                    path[i] = j;
                }
            }
        }

        /*for(auto i : path) {
            std::cout << i << " ";
        }*/

        vector<int> result;
        if(dp[0] == INT_MAX) return result;
        int index = 0;
        while(index != -1) {
            result.push_back(index + 1);
            index = path[index];
        }

        return result;
    }
};