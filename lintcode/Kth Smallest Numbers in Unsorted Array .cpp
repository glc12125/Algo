class Solution {
private:
    int quickSelect(vector<int> & nums, int start, int end, int k) {
        if(start >= end) return nums[k];
        int left = start;
        int right = end;

        int pivot = nums[left + (right - left) / 2];
        while(left <= right) {
            while(left <= right && nums[left] < pivot) ++left;
            while(left <= right && nums[right] > pivot) --right;

            if(left <= right) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                ++left;
                --right;
            }
        }

        if(k <= right) return quickSelect(nums, start, right, k);
        if(k >= left) return quickSelect(nums, left, end, k);
        return nums[k];
    }


public:
    /**
     * @param k: An integer
     * @param nums: An integer array
     * @return: kth smallest element
     */
    int kthSmallest(int k, vector<int> &nums) {
        if(k < 1 || nums.size() < k || nums.size() == 0) return -1;
        return quickSelect(nums, 0, nums.size() - 1, k - 1);
    }
};