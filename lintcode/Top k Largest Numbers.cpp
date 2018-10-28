class Solution {
private:
    std::priority_queue<int, std::vector<int>, std::greater<int> > m_q;

public:
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
    vector<int> topk(vector<int> &nums, int k) {
        for(auto num : nums) {
            m_q.push(num);
            if(m_q.size() > k) m_q.pop();
        }

        std::vector<int> result;
        while(!m_q.empty()) {
            auto num = m_q.top();
            m_q.pop();
            result.push_back(num);
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};