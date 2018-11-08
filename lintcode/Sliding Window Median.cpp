class Solution {
private:
    int m_len;
    multiset<int, std::greater<int> > m_maxHeap;
    multiset<int> m_minHeap;

    void addNum(int num) {
        m_maxHeap.insert(num);
        if(m_len % 2) {
            m_minHeap.insert(*m_maxHeap.begin());
            m_maxHeap.erase(m_maxHeap.begin());
        } else {
            if(m_minHeap.size() == 0) {
                ++m_len;
                return;
            } else if(*m_maxHeap.begin() > *m_minHeap.begin()) {
                int bigger = *m_maxHeap.begin();
                int smaller = *m_minHeap.begin();
                m_maxHeap.erase(m_maxHeap.begin());
                m_minHeap.erase(m_minHeap.begin());
                m_maxHeap.insert(smaller);
                m_minHeap.insert(bigger);
            }
        }
        ++m_len;
    }

    void adjust(int numToDelete, int numToAdd) {

        if(m_maxHeap.find(numToDelete) != m_maxHeap.end()) {
            m_maxHeap.erase(m_maxHeap.find(numToDelete));
            m_maxHeap.insert(numToAdd);
        } else {
            m_minHeap.erase(m_minHeap.find(numToDelete));
            m_minHeap.insert(numToAdd);
        }

        if(m_maxHeap.size() > 0 && m_minHeap.size() > 0 && *m_maxHeap.begin() > *m_minHeap.begin()) {
            int bigger = *m_maxHeap.begin();
            int smaller = *m_minHeap.begin();
            m_maxHeap.erase(m_maxHeap.begin());
            m_minHeap.erase(m_minHeap.begin());
            m_maxHeap.insert(smaller);
            m_minHeap.insert(bigger);
        }
    }

    int getMedian() {
        return *m_maxHeap.begin();
    }
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        m_maxHeap.clear();
        m_minHeap.clear();
        m_len = 0;

        int len = nums.size();
        if(len == 0) return {};

        int loopMax = std::min(k, len);

        vector<int> result;
        for(int i = 0; i < loopMax; ++i) {
            addNum(nums[i]);
        }
        if(k > len) {
            return result;
        }

        for(int i = k; i < len; ++i) {
            // Remove the front
            // add number
            result.push_back(getMedian());
            adjust(nums[i-k], nums[i]);
        }
        result.push_back(getMedian());
        return result;
    }
};