class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: An integer
     * @return: An integer
     */
    int twoSum6(vector<int> &nums, int target) {
        int len = nums.size();
        if(len == 0) return 0;
        std::sort(nums.begin(), nums.end());
        
        int left = 0;
        int right = len - 1;
        int count = 0;
        while(left < right) {
            if(nums[left] + nums[right] == target) {
                ++count;
                ++left;
                --right;
                while(nums[left] == nums[left-1]) ++left;
                while(nums[right] == nums[right + 1]) --right;
            } else if (nums[left] + nums[right] < target) {
                ++left;
            } else --right;
        }
        return count;
    }
};

// time O(n) space O(n)
int twoSum6(vector<int> &nums, int target) {
    int len = nums.size();
    if(len < 2) return 0;
    std::unordered_map<int, int> counts;
    for(auto i : nums) {
        ++counts[i];
    }
    int count = 0;
    for(auto i : nums) {
        if(counts.count(target - i) > 0) {
            if(i == target - i) {
                if(counts[i] > 1) ++count;
            } else {
                ++count;
            }
            counts.erase(i);
            counts.erase(target-i);
        }
    }
    return count;
}