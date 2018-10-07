class Solution {
public:
    /**
     * @param nums: an integer array
     * @param target: An integer
     * @return: the difference between the sum and the target
     */
    int twoSumClosest(vector<int> &nums, int target) {
        int len = nums.size();
        std::sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int start = 0;
        int end = len - 1;
        while(start < end) {
            int sum = nums[start] + nums[end];
            if(sum < target) {
                diff = std::min(target - sum, diff);
                ++start;
            } else if (sum > target) {
                diff = std::min(sum - target, diff);
                --end;
            } else {return 0;}
        }
        return diff;
    }
};