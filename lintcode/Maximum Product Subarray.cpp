class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An integer
     */
    int maxProduct(vector<int> &nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];
        vector<int> biggest(len);
        vector<int> smallest(len);
        biggest[0] = nums[0];
        smallest[0] = nums[0];
        for(int i = 1; i < len; ++i) {
            biggest[i] = std::max(nums[i], std::max(nums[i] * biggest[i-1], nums[i] * smallest[i-1]));
            smallest[i] = std::min(nums[i], std::min(nums[i] * biggest[i-1], nums[i] * smallest[i-1]));
        }

        int result = INT_MIN;
        for(auto i : biggest) {
            result = std::max(result, i);
        }
        return result;
    }
};