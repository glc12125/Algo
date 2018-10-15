class Solution {
private:
    int quickSelection(std::vector<int>& nums, int start, int end, int color) {
        int left = start;
        int right = end;
        int pivot = color;
        while(left <= right) {
            while(left <= right && nums[left] < color) ++left;
            while(left <= right && nums[right] >= color) --right;

            if(left <= right) {
                swap(nums[left], nums[right]);
                ++left;
                --right;
            }
        }

        return left;
    }

    void swap(int& a, int&b) {
        int temp = a;
        a = b;
        b = temp;
    }
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2
     * @return: nothing
     */
    void sortColors(vector<int> &nums) {
        int len = nums.size();
        if(len == 0) return;
        int colors[3] = {1,2};
        int start = 0;
        for(auto color : colors) {
            start = quickSelection(nums, start, len - 1, color);
        }
    }
};