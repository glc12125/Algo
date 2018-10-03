class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        int size = nums.size();
        int start = 0;
        int end = size - 1;
        int mid;
        while(start + 1 < end) {
            mid = (start + end) / 2;
            if(nums[mid] > nums[mid+1]) return nums[mid+1];
            if(nums[mid] < nums[start]) end = mid;
            else start = mid;
        }
        
        if(nums[start] > nums[end]) return nums[end];
        else return nums[0];
    }
};