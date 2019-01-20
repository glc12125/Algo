class Solution {
public:
    /**
     * @param nums: a mountain sequence which increase firstly and then decrease
     * @return: then mountain top
     */
    int mountainSequence(vector<int> &nums) {
        int len = nums.size();
        if(len == 0) return -1;

        int start = 0;
        int end = nums.size()-1;

        while(start + 1 < end) {
            int mid = start + (end - start)/2;
            if(nums[mid] > nums[mid+1]) {
                end = mid;
            } else {
                start = mid;
            }
        }

        return std::max(nums[start], nums[end]);
    }
};