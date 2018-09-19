class Solution {
public:
    /**
     * @param nums: an array
     * @param k: an integer
     * @return: the maximum average value
     */
    double findMaxAverage(vector<int> &nums, int k) {
        double sum = 0.0;
        for(int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        double maxSum = sum;
        int size = nums.size();
        for(int i = k; i < size; ++i) {
            sum += nums[i] - nums[i-k];
            maxSum = std::max(maxSum, sum);
        }
        return maxSum/k;
    }
};