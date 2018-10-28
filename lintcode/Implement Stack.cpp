class Stack {
private:
    std::vector<int> m_container;
public:
    /*
     * @param x: An integer
     * @return: nothing
     */
    void push(int x) {
        m_container.push_back(x);
    }

    /*
     * @return: nothing
     */
    void pop() {
        m_container.pop_back();
    }

    /*
     * @return: An integer
     */
    int top() {
        return m_container.back();
    }

    /*
     * @return: True if the stack is empty
     */
    bool isEmpty() {
        return m_container.empty();
    }
};