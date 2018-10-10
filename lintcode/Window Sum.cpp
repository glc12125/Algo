class Solution {
public:
    /**
     * @param nums: a list of integers.
     * @param k: length of window.
     * @return: the sum of the element inside the window at each moving.
     */
    vector<int> winSum(vector<int> &nums, int k) {
        int len = nums.size();
        if(len == 0) return {};
        if(k >= len) return {std::accumulate(nums.begin(), nums.end(), 0)};
        
        int sum = 0;
        std::vector<int> result;
        for(int i = 0; i < len; ++i) {
            sum += nums[i];
            if(i < k - 1) continue;
            sum -= (i-k > -1 ? nums[i-k] : 0);
            result.push_back(sum);
        }
        return result;
    }
};