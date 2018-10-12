class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        int len = nums.size();
        if(len == 0) return -1;
        
        int left = 0;
        int right = len - 1;
        int mid;
        while(left + 1 < right) {
            mid = left + (right - left) / 2;
            if(nums[mid] == nums[right]) --right;
            else if(nums[mid] > nums[right]) left = mid;
            else right = mid;
        }
        
        if(nums[left] < nums[right]) return nums[left];
        else return nums[right];
    }
};