class Solution {
public:
    /**
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int findPosition(vector<int> &nums, int target) {
        int len = nums.size();
        if(len == 0) return -1;
        int left = 0;
        int right = len - 1;
        int mid;
        while(left + 1 < right) {
            mid = left + (right - left) / 2;
            if(nums[mid] < target) left = mid;
            else right = mid;
        }

        if(nums[left] == target) return left;
        if(nums[right] == target) return right;
        return -1;
    }
};