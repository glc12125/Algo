class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        int len = A.size();

        vector<vector<bool> > dp(2, vector<bool>(m + 1, false));
        dp[0][0] = true;

        for(int i = 1; i <= len; ++i) {
            for(int j = 0; j <= m; ++j) {
                dp[i%2][j] = dp[(i-1)%2][j];
                if(j >= A[i-1] && dp[(i-1)%2][j - A[i-1]]) dp[i%2][j] = true;
            }
        }

        for(int i = m; i >= 0; --i) {
            if(dp[len%2][i]) return i;
        }
        return 0;
    }
};

//
class Solution {
public:
    /**
     * @param nums: the given array
     * @return: the minimum difference between their sums
     */
    int findMin(vector<int> &nums) {
        int len = nums.size();
        if(len == 0) return 0;

        long long sum = accumulate(nums.begin(), nums.end(), 0);

        long long capacity = (sum >> 1);
        vector<vector<bool> > dp(2, vector<bool>(capacity + 1, false));

        dp[0][0] = true;
        for(int i = 1; i <= len; ++i) {
            for(int j = 0; j <= capacity; ++j) {
                dp[i%2][j] = dp[(i-1)%2][j];
                if(j >= nums[i-1] && dp[(i-1)%2][j - nums[i-1]]) dp[i%2][j] = true;
            }
        }

        long long maxSumHalf = -1;
        for(int j = capacity; j >= 0; --j) {
            if(dp[len%2][j]) {
                maxSumHalf = j;
                break;
            }
        }
        return sum - maxSumHalf - maxSumHalf;
    }
};