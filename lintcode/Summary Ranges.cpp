class Solution {
public:
    /**
     * @param nums:  a sorted integer array without duplicates
     * @return: the summary of its ranges
     */
    vector<string> summaryRanges(vector<int> &nums) {
        int len = nums.size();
        if(len == 0) return {};
        if(len == 1) return {to_string(nums[0])};

        int start = 0;
        int end = 1;
        vector<string> result;
        while(end < len) {
            if(nums[end] > nums[end - 1] + 1) {
                if(start + 1 == end) {
                    result.push_back(to_string(nums[start]));
                } else {
                    result.push_back(to_string(nums[start]) + "->" + to_string(nums[end-1]));
                }
                start = end;
            }
            ++end;
        }

        if(start + 1 == end) {
            result.push_back(to_string(nums[start]));
        } else {
            result.push_back(to_string(nums[start]) + "->" + to_string(nums[end-1]));
        }

        return result;
    }
};