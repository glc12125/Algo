class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int> &nums) {
        int len = nums.size();
        if(len == 0) return;
        sort(nums.begin(), nums.end());
        bool increasing = true;
        for(int i = 0; i < len - 1; ++i) {
            if(increasing) {
                if(nums[i] > nums[i+1]) swap(nums[i], nums[i+1]);
            } else {
                if(nums[i] < nums[i+1]) swap(nums[i], nums[i+1]);
            }
            increasing = !increasing;
        }
    }
};

// Without sorting
class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int> &nums) {
        int len = nums.size();
        if(len == 0) return;
        for(int i = 0; i < len - 1; ++i) {
            if(i % 2 == 0) {
                if(nums[i] > nums[i+1]) swap(nums[i], nums[i+1]);
            } else {
                if(nums[i] < nums[i+1]) swap(nums[i], nums[i+1]);
            }
        }
    }
};