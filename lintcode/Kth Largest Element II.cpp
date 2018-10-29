class Solution {
private:
    int quickSelect(std::vector<int> &nums, int start, int end, int k) {
        if(start >= end) return nums[k];

        int l = start;
        int r = end;
        int pivot = nums[start + (end - start) / 2];
        while(l <= r) {
            while(l <= r && nums[l] > pivot) ++l;
            while(l <= r && nums[r] < pivot) --r;

            if(l <= r) {
                std::swap(nums[l++], nums[r--]);
            }
        }

        if(k <= r) return quickSelect(nums, start, r, k);
        if(k >= l) return quickSelect(nums, l, end, k);
        return nums[k];
    }
public:
    /**
     * @param nums: an integer unsorted array
     * @param k: an integer from 1 to n
     * @return: the kth largest element
     */
    int kthLargestElement2(vector<int> &nums, int k) {
        int len = nums.size();
        return quickSelect(nums, 0, len - 1, k - 1);
    }
};