class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> &nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return {nums[0]};

        vector<int> dpPrev(len);
        vector<int> dpMax(len);
        dpPrev[0] = -1;
        dpMax[0] = 1;
        for(int i = 1; i < len; ++i) {
            dpPrev[i] = -1;
            dpMax[i] = 1;
            for(int j = i - 1; j > -1; --j) {
                if(nums[i] > nums[j] && dpMax[i] <= dpMax[j]) {
                    dpPrev[i] = j;
                    dpMax[i] = dpMax[j] + 1;
                }
            }
        }

        int maxLen = 1;
        for(int i = 0; i < len; ++i) {
            maxLen = std::max(maxLen, dpMax[i]);
        }
        return maxLen;
    }
};

// Time O(nlogn)
class Solution {
private:
    int firstGTE(const vector<int>& prevNums, int target) {
        int i = 0;
        int j = prevNums.size() - 1;
        while(i + 1 < j) {
            int mid = i + (j - i) / 2;
            if(prevNums[mid] < target) i = mid;
            else j = mid;
        }

        if(prevNums[i] >= target) return i;
        if(prevNums[j] >= target) return j;
        return 1; // Cannot use 0, because it was assigned INT_MIN and used as a place holder
    }
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> &nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return {nums[0]};

        vector<int> prevNums(len + 1, INT_MAX);
        prevNums[0] = INT_MIN;
        for(int i = 0; i < len; ++i) {
            int pos = firstGTE(prevNums, nums[i]);
            prevNums[pos] = nums[i];
        }

        for(int i = len; i > 0; --i) {
            if(prevNums[i] != INT_MAX) return i;
        }
        return 0;
    }
};