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
        vector<int> result(len, INT_MIN);
        for(int i = 0; i < len; ++i) {
            int curr = nums[i];
            while(!s.empty() && curr > nums[s.top()]) {
                result[s.top()] = curr;
                s.pop();
            }
            s.push(i);
        }
        if(!s.empty()) {
            for(int i = 0; i < len; ++i) {
                int curr = nums[i];
                while(!s.empty() && curr > nums[s.top()]) {
                    result[s.top()] = curr;
                    s.pop();
                }
                if(result[i] == INT_MIN) s.push(i);
            }
        }
        while(!s.empty()) {
            result[s.top()] = -1;
            s.pop();
        }
        return result;
    }
};