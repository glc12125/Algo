class Solution {
private:
    int select(int n, std::vector<int>& nums, int start, int end) {
        if(start >= end) return nums[n];
        int i = start;
        int j = end;
        int pivot = nums[(i+j)/2];
        while(i <= j) {
            while(i <= j && nums[i] > pivot) ++i;
            while(i <= j && nums[j] < pivot) --j;
            if(i<=j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                ++i;
                --j;
            }
        }
        
        if(n <= j) return select(n, nums, start, j);
        if(n >= i) return select(n, nums, i, end);
        return nums[n];
    }
public:
    /**
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
        int len = nums.size();
        if(len == 0 || n > len || n < 1) return -1;
        return select(n-1, nums, 0, len -1);
    }
};