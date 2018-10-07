class Solution {
public:
    /**
     * @param nums: an integer array
     * @return: nothing
     */
    void moveZeroes(vector<int> &nums) {
        int size = nums.size();
        int fillPosition = 0;
        int targetPosition = 0;
        while(targetPosition < size) {
            if(nums[targetPosition] != 0) {
                int temp = nums[fillPosition];
                nums[fillPosition] = nums[targetPosition];
                nums[targetPosition] = temp;
                ++fillPosition;
            }
            ++targetPosition;
        }
    }
};

// Fill zeros at the end only, no swap
class Solution {
public:
    /**
     * @param nums: an integer array
     * @return: nothing
     */
    void moveZeroes(vector<int> &nums) {
        int size = nums.size();
        int fillPosition = 0;
        int targetPosition = 0;
        while(targetPosition < size) {
            if(nums[targetPosition] != 0) {
                nums[fillPosition] = nums[targetPosition];
                ++fillPosition;
            }
            ++targetPosition;
        }
        while(fillPosition < size) {
            nums[fillPosition++] = 0;
        }
    }
};

// Minimize write operations
class Solution {
public:
    /**
     * @param nums: an integer array
     * @return: nothing
     */
    void moveZeroes(vector<int> &nums) {
        int size = nums.size();
        int fillPosition = 0;
        int targetPosition = 0;
        while(targetPosition < size) {
            if(nums[targetPosition] != 0) {
                if(nums[fillPosition] != nums[targetPosition])
                    nums[fillPosition] = nums[targetPosition];
                ++fillPosition;
            }
            ++targetPosition;
        }
        while(fillPosition < size) {
            if(nums[fillPosition] != 0)
                nums[fillPosition] = 0;
            ++fillPosition;
        }
    }
};