class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> &nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];

        vector<int> prefixSums(len + 1, 0);
        for(int i = 1; i < len + 1; ++i) {
            prefixSums[i] = prefixSums[i-1] + nums[i-1];
        }

        int min = INT_MAX;
        int max = INT_MIN;
        for(int i = 0; i < len + 1; ++i) {
            max = std::max(max, prefixSums[i] - min);
            min = std::min(min, prefixSums[i]);
        }

        return max;
    }
};