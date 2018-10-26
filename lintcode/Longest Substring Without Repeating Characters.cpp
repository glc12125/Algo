class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer
     */
    int lengthOfLongestSubstring(string &s) {
        int len = s.size();
        if(len <= 1) return len;
        
        int left = 0;
        int right = 0;
        std::unordered_set<int> uniqueContainer;
        int maxLen = INT_MIN;
        while(right < len) {
            while(uniqueContainer.count(s.at(right))) {
                uniqueContainer.erase(s.at(left++));
            }
            uniqueContainer.insert(s.at(right++));
            maxLen = std::max(maxLen, (int)uniqueContainer.size());
        }
        
        return maxLen;
    }
};