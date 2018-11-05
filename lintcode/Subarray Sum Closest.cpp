class Solution {
private:
    struct SumNode {
        int m_sum;
        int m_index;
        SumNode() = default;
        SumNode(int sum, int index) : m_sum(sum), m_index(index) {}
    };

    struct SumNodeCompare {
        bool operator()(const SumNode& s1, const SumNode& s2) const {
            return s1.m_sum < s2.m_sum;
        }
    };
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> &nums) {
        int len = nums.size();
        if(len == 0) return {};
        if(len == 1) return {0, 0};

        vector<int> prefixSum(len + 1, 0);
        vector<SumNode> temp(len);
        for(int i = 1; i <= len; ++i) {
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
            temp[i - 1] = SumNode(prefixSum[i], i - 1);
        }

        sort(temp.begin(), temp.end(), SumNodeCompare());

        int minDiff = INT_MAX;
        int index1 = 0;
        int index2 = 0;
        for(int i = 1; i < len; ++i) {
            if(temp[i].m_sum - temp[i-1].m_sum < minDiff) {
                minDiff = temp[i].m_sum - temp[i-1].m_sum;
                index1 = temp[i].m_index;
                index2 = temp[i-1].m_index;
            }
        }
        vector<int> result = {index1, index2};
        sort(result.begin(), result.end());
        result[0] += 1;
        return result;
    }
};