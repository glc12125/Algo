class Stack {
private:
    std::queue<int> m_q1;
    std::queue<int> m_q2;
public:
    /*
     * @param x: An integer
     * @return: nothing
     */
    void push(int x) {
        if(m_q1.empty()) m_q2.push(x);
        if(m_q2.empty()) m_q1.push(x);
    }

    /*
     * @return: nothing
     */
    void pop() {
        if(m_q1.empty()) {
            while(m_q2.size() > 1) {
                m_q1.push(m_q2.front());
                m_q2.pop();
            }
            m_q2.pop();
        } else {
            while(m_q1.size() > 1) {
                m_q2.push(m_q1.front());
                m_q1.pop();
            }
            m_q1.pop();
        }
    }

    /*
     * @return: An integer
     */
    int top() {
        int result;
        if(m_q1.empty()) {
            while(m_q2.size() > 1) {
                m_q1.push(m_q2.front());
                m_q2.pop();
            }
            result = m_q2.front();
            m_q1.push(result);
            m_q2.pop();
        } else {
            while(m_q1.size() > 1) {
                m_q2.push(m_q1.front());
                m_q1.pop();
            }
            result = m_q1.front();
            m_q2.push(result);
            m_q1.pop();
        }
        return result;
    }

    /*
     * @return: True if the stack is empty
     */
    bool isEmpty() {
        return m_q1.empty() && m_q2.empty();
    }
};