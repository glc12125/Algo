// This is essentionally coins in a line III
class Solution {
public:
    /**
     * @param nums: nums an array of scores
     * @return: check if player 1 will win
     */
    bool PredictTheWinner(vector<int> &nums) {
        int size = nums.size();
        if(size == 0) return true;

        vector<vector<int>> dp(size + 1, vector<int>(size + 1, 0));

        for(int len = 1; len <= size; ++len) {
            int maxI = size - len + 1;
            for(int i = 1; i <= maxI; ++i) {
                int j = i + len - 1;
                if(i == j) {
                    dp[i][j] = nums[i-1];
                    continue;
                }
                dp[i][j] = 0;
                if(i <= j - 2) {
                    // We use min because the other player wants to win as well
                    // I take i, the other take i + 1 or j
                    dp[i][j] = std::max(dp[i][j], nums[i-1] + std::min(dp[i+2][j], dp[i+1][j-1]));
                    // I take j, the other take i or j - 1
                    dp[i][j] = std::max(dp[i][j], nums[j-1] + std::min(dp[i+1][j-1], dp[i][j-2]));
                } else {
                    dp[i][j] = std::max(dp[i][j], std::max(nums[i-1], nums[j-1]));
                }
            }
        }

        return dp[1][size] >= accumulate(nums.begin(), nums.end(), 0) / 2;
    }
};

// Memoisation search
class Solution {
private:
    long long firstTotal(const vector<int> &nums, vector<vector<long long> >& dp, vector<vector<bool> >& visited, int start, int end) {
        if(visited[start][end]) return dp[start][end];
        visited[start][end] = true;
        if(start > end) dp[start][end] = 0;
        else if(start == end) dp[start][end] = nums[start];
        else if(start + 1 == end){
            dp[start][end] = std::max(nums[start], nums[end]);
        } else {
            long long left = std::min(firstTotal(nums, dp, visited, start + 2, end), firstTotal(nums, dp, visited, start + 1, end - 1)) + nums[start];
            long long right = std::min(firstTotal(nums, dp, visited, start, end - 2), firstTotal(nums, dp, visited, start + 1, end - 1)) + nums[end];
            dp[start][end] = std::max(left, right);
        }

        return dp[start][end];
    }
public:
    /**
     * @param nums: nums an array of scores
     * @return: check if player 1 will win
     */
    bool PredictTheWinner(vector<int> &nums) {
        int len = nums.size();
        if(len == 0) return true;
        if(len == 1) return true;
        if(len == 2) return true;

        vector<vector<long long> > dp(len, vector<long long>(len, 0));
        vector<vector<bool> > visited(len, vector<bool>(len, false));
        long long sum = std::accumulate(nums.begin(), nums.end(), 0);

        return firstTotal(nums, dp, visited, 0, len - 1) >= sum / 2;
    }
};