class Solution {
public:
    /**
     * @param nums:  an array of n integers
     * @param target: a target
     * @return: the number of index triplets satisfy the condition nums[i] + nums[j] + nums[k] < target
     */
    int threeSumSmaller(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int count = 0;
        for(int i = 0; i < len - 2; ++i) {
            int a = nums[i];
            int j = i + 1;
            int k = len - 1;
            int targetTwoSum = target - a;
            while(j < k) {
                int twoSum = nums[j] + nums[k];
                if(twoSum < targetTwoSum) {
                    count += k - j;
                    ++j;
                } else {
                    --k;
                }
            }
        }

        return count;
    }
};