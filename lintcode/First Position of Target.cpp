class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &nums, int target) {
        int size = nums.size();
        if(size == 0) return false;
        int start = 0;
        int end = size - 1;
        int mid;

        while(start + 1 < end) {
            mid = (start + end) / 2;
            if(nums[mid] < target) start = mid;
            else end = mid;
        }

        if(nums[start] == target) return start;
        if(nums[end] == target) return end;
        return -1;
    }
};