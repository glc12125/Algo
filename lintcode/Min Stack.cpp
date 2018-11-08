class MinStack {
private:
    int m_min;
    vector<int> m_mins;
    vector<int> m_container;
public:
    MinStack() {
        m_mins.clear();
        m_container.clear();
        m_min = INT_MAX;
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        m_container.push_back(number);
        m_min = std::min(m_min, number);
        m_mins.push_back(m_min);
    }

    /*
     * @return: An integer
     */
    int pop() {
        int result = m_container.back();
        m_container.pop_back();
        m_mins.pop_back();
        m_min = (m_mins.empty() ? INT_MAX : m_mins.back());
        return result;
    }

    /*
     * @return: An integer
     */
    int min() {
        return m_min;
    }
};