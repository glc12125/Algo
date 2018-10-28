class Solution {
private:
    int m_capacity;
    std::priority_queue<int, std::vector<int>, std::greater<int> > m_q;

public:
    /*
    * @param k: An integer
    */Solution(int k) : m_capacity(k) {
        // do intialization if necessary
    }

    /*
     * @param num: Number to be added
     * @return: nothing
     */
    void add(int num) {
        m_q.push(num);
        if(m_q.size() > m_capacity) m_q.pop();
    }

    /*
     * @return: Top k element
     */
    vector<int> topk() {
        std::priority_queue<int, std::vector<int>, std::greater<int> > temp(m_q);
        vector<int> result;
        while(!temp.empty()) {
            result.push_back(temp.top());
            temp.pop();
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};