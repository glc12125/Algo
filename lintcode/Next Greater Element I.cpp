class Solution {

public:
    /**
     * @param nums1: an array
     * @param nums2: an array
     * @return:  find all the next greater numbers for nums1's elements in the corresponding places of nums2
     */
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(len1 == 0 || len2 == 0) return {};

        stack<int> s;
        unordered_map<int, int> nextGreaterMem;
        for(int i = 0; i <= len2; ++i) {
            int curr = (i == len2 ? INT_MAX : nums2[i]);
            while(!s.empty() && nums2[s.top()] < curr) {
                nextGreaterMem[nums2[s.top()]] = (curr == INT_MAX ? -1 : curr);
                s.pop();
            }
            s.push(i);
        }

        vector<int> result(len1, -1);
        for(int i = 0; i < len1; ++i) {
            if(nextGreaterMem.count(nums1[i])) result[i] = nextGreaterMem[nums1[i]];
        }

        return result;
    }
};