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

// Binary Search, time O(N)
class Solution {
public:
    /**
     * @param nums: The number array
     * @return: Return the single number
     */
    int getSingleNumber(vector<int> &nums) {
        int len = nums.size();
        if(len == 1) return nums[0];

        int left = 0;
        int right = len - 1;
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(mid % 2 == 0) {
                // First enter here
                if(nums[mid-1] == nums[mid]) {
                    right = mid;
                } else {
                    left = mid;
                }
            } else {
                if(nums[mid-1] == nums[mid]) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
        }

        if(nums[left] == nums[left - 1]) return nums[right];
        else return nums[left];
    }
};