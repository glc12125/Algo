class Solution {
public:
    /**
     * @param nums: an array
     * @param n: an integer
     * @return: the minimum number of patches required
     */
    int minPatches(vector<int> &nums, int n) {
        if(n == 0) return 0;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        long missing = 1;
        int count = 0;
        int i = 0;
        while(missing <= n) {
            if(i < len && nums[i] <= missing) {
                missing += nums[i++];
            } else {
                ++count;
                missing += missing;
            }
        }
        return count;
    }
};