// Time O(NlogK)
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @param k: An integer
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int len = nums.size();
        if(len == 0) return {};

        multiset<int, std::greater<int> > s;

        int maxLen = std::min(k, len);
        for(int i = 0; i < maxLen; ++i) {
            s.insert(nums[i]);
        }

        if(maxLen == len) return {*s.begin()};

        vector<int> result;
        for(int i = k; i < len; ++i) {
            result.push_back(*s.begin());
            s.erase(s.find(nums[i-k]));
            s.insert(nums[i]);
        }
        result.push_back(*s.begin());
        return result;
    }
};