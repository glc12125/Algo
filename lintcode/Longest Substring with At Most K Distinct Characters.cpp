class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        if(k <= 0) return 0;
        int len = s.size();
        if(len < 2) return len;
        
        int left = 0;
        int right = 0;
        std::unordered_map<char, int> uniqueContainer;
        int maxLen = INT_MIN;
        while(right < len) {
            ++uniqueContainer[s.at(right++)];
            while(uniqueContainer.size() > k) {
                if(--uniqueContainer[s.at(left)] == 0) {
                    uniqueContainer.erase(s.at(left));
                }
                ++left;
            }
            maxLen = std::max(maxLen, right - left);
        }
        
        return maxLen;
    }
};