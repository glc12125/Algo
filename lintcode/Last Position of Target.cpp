class Solution {
public:
    /**
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int lastPosition(vector<int> &nums, int target) {
        int size = nums.size();
        if(size == 0) return -1;

        int start = 0;
        int end = size - 1;
        int middle;
        while(start + 1 < end) {
            middle = (start + end) / 2;
            if(nums[middle] > target) end = middle;
            else start = middle;
        }

        if(nums[end] == target) return end;
        if(nums[start] == target) return start;

        return -1;
    }
};