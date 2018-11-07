class Solution {
private:
    int m_len;
    priority_queue<int, vector<int>> m_maxHeap;
    priority_queue<int, vector<int>, std::greater<int>> m_minHeap;

    void addNum(int num) {
        m_maxHeap.push(num);
        if(m_len % 2) {
            m_minHeap.push(m_maxHeap.top());
            m_maxHeap.pop();
        } else {
            if(m_minHeap.size() == 0) {
                ++m_len;
                return;
            } else if(m_maxHeap.top() > m_minHeap.top()) {
                int bigger = m_maxHeap.top();
                m_maxHeap.pop();
                int smaller = m_minHeap.top();
                m_minHeap.pop();
                m_minHeap.push(bigger);
                m_maxHeap.push(smaller);
            }
        }
        ++m_len;
    }

    int getMedian() {
        return m_maxHeap.top();
    }
public:
    /**
     * @param nums: A list of integers
     * @return: the median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        m_len = 0;
        vector<int> result;

        for(auto num : nums) {
            addNum(num);
            result.push_back(getMedian());
        }
        return result;
    }
};