// Time O(N), space O(1)
class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: find a  majority number
     */
    int majorityNumber(vector<int> &nums) {
        if (nums.size() == 0) {
            return -1;
        }
        int count = 0;
        int major = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (major == nums[i]) {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                major = nums[i];
                count++;
            }
        }
        return major;
    }
};