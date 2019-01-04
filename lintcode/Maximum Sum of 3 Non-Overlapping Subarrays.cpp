// Naive direct Prefix Sum, time O(N^3)
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

// DP, time O(N), space O(N), what if we need to return a group of n sub-arrays with max sum?

class Solution {
public:
    /**
     * @param nums: an array
     * @param k: an integer
     * @return: three non-overlapping subarrays with maximum sum
     */
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
        int len = nums.size();

        vector<long long> prefixSum(len, 0);
        prefixSum[0] = nums[0];
        for(int i = 1; i < len; ++i) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
            if(i >= k) {
                prefixSum[i] -= nums[i-k];
            }
        }

        vector<int> left(len, 0);
        vector<int> right(len, 0);
        left[k-1] = k - 1;
        for(int i = k; i < len; ++i) {
            left[i] = (prefixSum[i] > prefixSum[left[i-1]] ? i : left[i-1]);
        }

        right[len-1] = len - 1;
        for(int i = len - 2; i >= 0; --i) {
            right[i] = (prefixSum[i] > prefixSum[right[i+1]] ? i : right[i+1]);
        }

        long long maxSum = INT_MIN;
        vector<int> result(3);

        for(int i = 2 * k - 1; i <= len - k - 1; ++i) {
            long long newSum = prefixSum[left[i-k]] + prefixSum[i] + prefixSum[right[i+k]];
            if(newSum > maxSum) {
                maxSum = newSum;
                result = {left[i-k] - k + 1, i - k + 1, right[i+k] - k + 1};
            }
        }

        return result;
    }
};