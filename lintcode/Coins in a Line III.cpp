class Solution {
private:
    long long firstTotal(const vector<int> &values, vector<vector<long long> >& dp, vector<vector<bool> >& visited, int start, int end) {
        if(visited[start][end]) return dp[start][end];
        visited[start][end] = true;
        if(start > end) dp[start][end] = 0;
        else if(start == end) dp[start][end] = values[start];
        else if(start + 1 == end){
            dp[start][end] = std::max(values[start], values[end]);
        } else {
            long long left = std::min(firstTotal(values, dp, visited, start + 2, end), firstTotal(values, dp, visited, start + 1, end - 1)) + values[start];
            long long right = std::min(firstTotal(values, dp, visited, start, end - 2), firstTotal(values, dp, visited, start + 1, end - 1)) + values[end];
            dp[start][end] = std::max(left, right);
        }

        return dp[start][end];
    }
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        int len = values.size();
        if(len == 0) return false;
        if(len == 1) return true;
        if(len == 2) return false;

        vector<vector<long long> > dp(len, vector<long long>(len, 0));
        vector<vector<bool> > visited(len, vector<bool>(len, false));
        long long sum = std::accumulate(values.begin(), values.end(), 0);

        return firstTotal(values, dp, visited, 0, len - 1) > sum / 2;
    }
};

// Time O(N^2), space O(N^2)
class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        int len = values.size();
        if(len == 0) return false;

        vector<vector<int>> dp(len, vector<int>(len));

        for(int i = 0; i < len; ++i) {
            dp[i][i] = values[i];
        }

        for(int l = 2; l <= len; ++l) {
            for(int i = 0; i <= len - l; ++i) {
                int j = i + l - 1;
                dp[i][j] = std::max(values[i] - dp[i+1][j], values[j] - dp[i][j-1]);
            }
        }

        return dp[0][len-1] > 0;
    }
};