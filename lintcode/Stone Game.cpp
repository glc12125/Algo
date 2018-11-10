class Solution {
private:
    long long memoSearch(const vector<int>& A, const vector<long long>& prefixSum, int start, int end, vector<vector<long long> >& dp, vector<vector<bool> >& visited) {
        if(visited[start][end]) return dp[start][end];
        visited[start][end] = true;
        if(start > end) dp[start][end] = INT_MAX;
        else if(start == end) dp[start][end] = 0;
        else if(start + 1 == end) dp[start][end] = A[start] + A[end];
        else {
            dp[start][end] = INT_MAX;
            long long mergeCost = prefixSum[end+1] - prefixSum[start];
            for(int k = start; k < end; ++k) {
                dp[start][end] = std::min(dp[start][end], memoSearch(A, prefixSum, start, k, dp, visited) + memoSearch(A, prefixSum, k + 1, end, dp, visited));
            }
            dp[start][end] += mergeCost;
        }

        return dp[start][end];
    }
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int stoneGame(vector<int> &A) {
        int len = A.size();
        if(len <= 0) return 0;

        vector<long long> prefixSum(len + 1, 0);
        for(int i = 1; i <= len; ++i) {
            prefixSum[i] = prefixSum[i-1] + A[i-1];
        }

        vector<vector<long long> > dp(len, vector<long long>(len, 0));
        vector<vector<bool> > visited(len, vector<bool>(len, false));

        return memoSearch(A, prefixSum, 0, len - 1, dp, visited);
    }
};