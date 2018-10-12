class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: An integer
     * @return: An integer
     */
    int twoSum6(vector<int> &nums, int target) {
        int len = nums.size();
        if(len == 0) return 0;
        std::sort(nums.begin(), nums.end());
        
        int left = 0;
        int right = len - 1;
        int count = 0;
        while(left < right) {
            if(nums[left] + nums[right] == target) {
                ++count;
                ++left;
                --right;
                while(nums[left] == nums[left-1]) ++left;
                while(nums[right] == nums[right + 1]) --right;
            } else if (nums[left] + nums[right] < target) {
                ++left;
            } else --right;
        }
        return count;
    }
};