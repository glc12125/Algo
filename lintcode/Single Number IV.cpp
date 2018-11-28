class Solution {
public:
    /**
     * @param nums: The number array
     * @return: Return the single number
     */
    int getSingleNumber(vector<int> &nums) {
        int len = nums.size();
        for(int i = 0; i < len; ++i) {
            if(i == 0 && nums[i] != nums[i+1]) return nums[i];
            if(i == len - 1 && nums[i] != nums[i-1]) return nums[i];
            if(nums[i-1] != nums[i] && nums[i] != nums[i+1]) return nums[i];
        }
        return -1;
    }
};