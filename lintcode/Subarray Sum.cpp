class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums) {
        int len = nums.size();
        if(len == 0) return {};
        vector<int> prefixSum(len + 1, 0);

        for(int i = 1; i < len + 1; ++i) {
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }

        unordered_map<int, int> uniqueSums;
        vector<int> result;
        for(int i = 0; i < len + 1; ++i) {
            //if(nums[i-1] == 0) return {i-1, i-1};
            if(uniqueSums.count(prefixSum[i])) {
                result.push_back(uniqueSums[prefixSum[i]]);
                result.push_back(i-1);
                return result;
            }
            uniqueSums[prefixSum[i]] = i;
        }
        return result;
    }
};