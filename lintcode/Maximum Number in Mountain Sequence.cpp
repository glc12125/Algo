class Solution {
public:
    /**
     * @param nums: a mountain sequence which increase firstly and then decrease
     * @return: then mountain top
     */
    int mountainSequence(vector<int> &nums) {
        int start = 0; 
        int end = nums.size() - 1;
        int mid;
        while(start + 1 < end) {
            mid = (start + end) / 2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return nums[mid];
            if(nums[mid] > nums[mid-1]) start = mid;
            else end = mid;
        }
        
        return std::max(nums[start], nums[end]);
    }
};