// Prefix Sum, time O(N^3)
class Solution {
public:
    /**
     * @param nums: an array
     * @param k: an integer
     * @return: three non-overlapping subarrays with maximum sum
     */
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
        int len = nums.size();

        vector<long long> prefixSum(len + 1, 0);

        for(int i = 1; i <= len; ++i) {
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }

        long long maxSum = INT_MIN;
        vector<int> result = {INT_MAX, INT_MAX, INT_MAX};
        int firstMax = len - 3 * k;
        for(int i = 0; i <= firstMax; ++i) {
            int firstSum = prefixSum[i+k] - prefixSum[i];
            int secondMax = len - 2 * k;
            for(int j = i + k; j <= secondMax; ++j) {
                int secondSum = prefixSum[j + k] - prefixSum[j];
                int thirdMax = len - k;
                for(int l = j + k; l <= thirdMax; ++l) {
                    int thirdSum = prefixSum[l + k] - prefixSum[l];
                    long long newSum = firstSum + secondSum + thirdSum;
                    if(newSum >= maxSum) {
                        if(maxSum == newSum) {
                            result = std::min(result, {i, j, l});
                        } else {
                            result = {i, j, l};
                            maxSum = newSum;
                        }
                    }
                }
            }
        }

        return result;
    }
};
