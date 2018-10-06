class Solution {
public:
    /**
     * @param nums: an array of Integer
     * @param target: target = nums[index1] + nums[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while(start < end) {
            int sum = nums[start] + nums[end];
            if( sum == target) {
                return {start+1, end+1};
            } else if (sum < target) {++start;}
            else {--end;}
        }
        return {};
    }
};