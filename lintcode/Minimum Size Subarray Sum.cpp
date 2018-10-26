class Solution {
public:
    /**
     * @param nums: an array of integers
     * @param s: An integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum < s) return -1;
        int len = nums.size();
        if(sum == s) return len;
        int left = 0;
        int right = 0;
        int currSum = 0;
        int result = INT_MAX;
        
        while(right < len) {
            currSum += nums[right];
            
            while(currSum >= s) {
                result = std::min(result, right - left + 1);
                currSum -= nums[left++];
            }
            ++right;
        }
        
        return result == INT_MAX ? -1 : result;
    }
};

// Move the first pointer instead
class Solution {
public:
    int minSubArrayLen(vector<int>& nums, int s) {
        int j = 0, i = 0;
        int sum =0;
        int ans = INT_MAX;
        int max = nums.size();
        for(i = 0; i < max; ++i) {
            while(j < max && sum < s) {
                sum += nums[j];
                ++j;
            }
            if(sum >=s) {
                ans = min(ans, j - i);
            }
            sum -= nums[i];
        }
        if(ans == INT_MAX)
            ans = -1;
        return ans;
    }
};