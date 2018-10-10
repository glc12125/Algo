class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: an integer
     * @return: an integer
     */
    int twoSum5(vector<int> &nums, int target) {
        int len = nums.size();
        if(len < 2) return 0;
        
        std::sort(nums.begin(), nums.end());
        int left = 0;
        int right = len - 1;
        int sum;
        int count = 0;
        while(left + 1 < right) {
            sum = nums[left] + nums[right];
            if(sum > target) --right;
            else {
                count += right - left;
                ++left;
            }
        }
        if(nums[left] + nums[right] <= target) ++count;

        return count;
    }
};