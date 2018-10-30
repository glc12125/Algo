class Solution {
public:
    /**
     * @param num: A list of integers
     * @return: An integer
     */
    int longestConsecutive(vector<int> &num) {
        std::unordered_set<int> uniqueNums(num.begin(), num.end());

        int longest = 1;
        for(auto i : num) {
            int smaller = i - 1;
            while(uniqueNums.count(smaller)) {
                uniqueNums.erase(smaller);
                --smaller;
            }
            int bigger = i + 1;
            while(uniqueNums.count(bigger)) {
                uniqueNums.erase(bigger);
                ++bigger;
            }

            longest = std::max(longest, bigger - smaller - 1);
        }

        return longest;
    }
};