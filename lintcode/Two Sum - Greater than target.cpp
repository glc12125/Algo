class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: An integer
     * @return: an integer
     */
    int twoSum2(vector<int> &nums, int target) {
        int len = nums.size();
        if(len < 2) return 0;
        
        std::sort(nums.begin(), nums.end());
        int left = 0;
        int right = len - 1;
        int count = 0;
        while(left < right) {
            if(nums[left] + nums[right] > target) {
                count += (right - left);
                --right;
            } else {
                ++left;
            }
        }
        
        return count;
    }
};