class Solution {
public:
    /**
     * @param nums: the arrays
     * @param k: the distance of the same number
     * @return: the ans of this question
     */
    string sameNumber(vector<int> &nums, int k) {
        unordered_map<int, int> s;
        auto size = nums.size();
        for(int i = 0; i < size; ++i) {
            if(s.count(nums[i]) > 0)
                if(i - s[nums[i]] < k) return "YES";
            s[nums[i]] = i;
        }

        return "NO";
    }
};