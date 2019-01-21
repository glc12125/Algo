class Solution {
public:
    /*
     * @param nums: an array of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        int len = nums.size();
        if(len <= 1) return;

        int l = 0;
        int r = len - 1;
        while(l <= r) {
            while(l <= r && nums[l] % 2) { ++l;}
            while(l <= r && nums[r] % 2 == 0) { --r;}
            if(l <= r) {
                swap(nums[l++], nums[r--]);
            }
        }
    }
};