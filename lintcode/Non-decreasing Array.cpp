class Solution {
public:
    /**
     * @param nums: an array
     * @return: if it could become non-decreasing by modifying at most 1 element
     */
    bool checkPossibility(vector<int> &nums) {
        int size = nums.size();
        int i = 1;
        for(; i < size; ++i) {
            if(nums[i] < nums[i-1]) {
                break;
            }
        }
        if (i == 0) return true;
        else {
            vector<int> copy(nums);
            copy[i-1] = copy[i];
            std::sort(copy.begin(), copy.end());
            int diff = 0;
            for(int j = 0; j < size; ++j) {
                if(copy[j] != nums[j]) {
                    if(++diff > 1) return false;
                }
            }
            return true;
        }
    }
};