class Solution {
public:
    /**
     * @param nums: an array
     * @return: the Next Greater Number for every element
     */
    vector<int> nextGreaterElements(vector<int> &nums) {
        int len = nums.size();
        if(len == 0) return {};
        stack<int> s;
        vector<int> result(len, -1);
        int doubleLen = len << 1;
        for(int i = 0; i < doubleLen; ++i) {
            int curr = nums[i%len];
            while(!s.empty() && curr > nums[s.top()]) {
                result[s.top()] = curr;
                s.pop();
            }
            if(i < len) s.push(i);
        }
        return result;
    }
};