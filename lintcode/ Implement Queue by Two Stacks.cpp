class MyQueue {
private:
    std::stack<int> m_mainContainer;
    std::stack<int> m_buffer;
    
    void fillMainContainer(){
        while(!m_buffer.empty()) {
            m_mainContainer.push(m_buffer.top());
            m_buffer.pop();
        }
    }
public:
    MyQueue() {
        // do intialization if necessary
    }

    /*
     * @param element: An integer
     * @return: nothing
     */
    void push(int element) {
        m_buffer.push(element);
    }

    /*
     * @return: An integer
     */
    int pop() {
        if(!m_mainContainer.empty()) {
            int result = m_mainContainer.top();
            m_mainContainer.pop();
            return result;
        }
        fillMainContainer();
        if(!m_mainContainer.empty()) {
            int result = m_mainContainer.top();
            m_mainContainer.pop();
            return result;
        } else return -1;
    }

    /*
     * @return: An integer
     */
    int top() {
        if(!m_mainContainer.empty()) {
            return m_mainContainer.top();
        }
        fillMainContainer();
        if(!m_mainContainer.empty()) {
            return m_mainContainer.top();
        } else return -1;
    }
};