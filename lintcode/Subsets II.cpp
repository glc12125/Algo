class Solution {
private:
    void btFind(const std::vector<int>& nums, int startIndex,
                std::vector<int>& subset, std::vector<std::vector<int> >& result) {
        result.push_back(subset);
        int size = nums.size();
        for(int i = startIndex; i < size; ++i) {
            if(i != 0 && nums[i-1] == nums[i] && i > startIndex) continue;
            subset.push_back(nums[i]);
            btFind(nums, i + 1, subset, result);
            subset.pop_back();
        }
    }
public:
    /**
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        std::vector<std::vector<int> > result;
        int size = nums.size();
        if(size == 0) return {{}};

        std::sort(nums.begin(), nums.end());

        std::vector<int> subset;
        btFind(nums, 0, subset, result);
        return result;
    }
};