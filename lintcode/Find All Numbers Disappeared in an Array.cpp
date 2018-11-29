class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: return a list of integers
     */
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> result;

        for(auto num : nums) {
            int index = abs(num) - 1;
            if(nums[index] > 0) nums[index] = -nums[index];
        }

        auto s = nums.size();
        for(int i = 0; i < s; ++i)
            if(nums[i] > 0) result.push_back(i+1);

        return result;
    }
};