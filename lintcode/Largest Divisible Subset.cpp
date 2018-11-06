class Solution {
private:
    struct Node {
        int m_prevIndex;
        int m_len;
        Node () = default;
        Node (int prevIndex, int len) : m_prevIndex(prevIndex), m_len(len) {}
    };

public:
    /*
     * @param nums: a set of distinct positive integers
     * @return: the largest subset
     */
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        int len = nums.size();
        if(len == 0) return {};
        sort(nums.begin(), nums.end());

        vector<Node> dp(len);
        dp[0] = Node(-1, 1);
        for(int i = 1; i < len; ++i) {
            dp[i] = Node(-1, 1);
            for(int j = i - 1; j > -1; --j) {
                if(nums[i] % nums[j] == 0) {
                    dp[i] = Node(j, dp[j].m_len + 1);
                    break;
                }
            }
        }

        int maxLen = INT_MIN;
        int maxIndex = 0;
        for(int i = 0; i < len; ++i) {
            if(maxLen < dp[i].m_len) {
                maxLen = dp[i].m_len;
                maxIndex = i;
            }
        }

        vector<int> result;
        int index = maxIndex;
        while(index != -1) {
            result.push_back(nums[index]);
            index = dp[index].m_prevIndex;
        }
        //std::reverse(result.begin(), result.end());
        return result;
    }
};