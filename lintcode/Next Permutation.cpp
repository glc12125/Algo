class Solution {
private:
    void reverseFromIndex(vector<int> &nums, int index, int end) {
        for(int i = index, j = end; i < j; ++i, --j){
            std::swap(nums[i], nums[j]);
        }
    }
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers
     */
    vector<int> nextPermutation(vector<int> &nums) {
        int len = nums.size();
        if(len == 0) return {};
        if(len == 1) return nums;

        int firstDecending = -1;
        for(int i = len - 1; i > 0; --i) {
            if(nums[i] > nums[i-1]) {
                firstDecending = i - 1;
                break;
            }
        }
        if(firstDecending != -1) {
            for(int i = len - 1; i > firstDecending; --i) {
                if(nums[i] > nums[firstDecending]) {
                    std::swap(nums[firstDecending], nums[i]);
                    break;
                }
            }
        }

        reverseFromIndex(nums, firstDecending + 1, len - 1);
        return nums;
    }
};