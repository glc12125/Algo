// Time O(NlogN), space O(N)
class Solution {
private:
    void mergeSort(std::vector<int>& prefixSum, std::vector<int>& temp, int start, int end, int lower, int upper, int& count) {
        if(start >= end) return;

        int mid = start + (end - start) / 2;
        mergeSort(prefixSum, temp, start, mid, lower, upper, count);
        mergeSort(prefixSum, temp, mid + 1, end, lower, upper, count);

        // Doing count
        int slow = start;
        int fast = start;
        for (int i = mid + 1; i <= end; i++) {
            while (slow <= mid && prefixSum[i] - prefixSum[slow] > upper) {
                slow++;
            }
            while (fast <= mid && prefixSum[i] - prefixSum[fast] >= lower) {
                fast++;
            }
            count += fast - slow;
        }

        // Merge
        merge(prefixSum, temp, start, end, mid);
    }

    void merge(std::vector<int>& nums, std::vector<int>& temp, int start, int end, int mid) {
        int index = start;
        int i = start;
        int j = mid + 1;
        while(i <= mid && j <= end) {
            if(nums[i] < nums[j]) {
                temp[index++] = nums[i++];
            } else {
                temp[index++] = nums[j++];
            }
        }

        while(i <= mid) {
            temp[index++] = nums[i++];
        }

        while(j <= end) {
            temp[index++] = nums[j++];
        }

        for(int k = start; k <= end; ++k) {
            nums[k] = temp[k];
        }
    }

public:
    /**
     * @param nums: a list of integers
     * @param lower: a integer
     * @param upper: a integer
     * @return: return a integer
     */
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        int len = nums.size();
        if(len == 0) return 0;

        vector<int> preSum (len + 1, 0);
        for(int i = 1; i <= len; ++i) {
            preSum[i] = preSum[i-1] + nums[i-1];
        }

        vector<int> temp(preSum);

        int count = 0;
        mergeSort(preSum, temp, 0, len, lower, upper, count);
        return count;
    }
};