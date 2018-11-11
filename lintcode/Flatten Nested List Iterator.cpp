/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    stack<NestedInteger> m_stack;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size() - 1; i > - 1; --i) {
            m_stack.push(nestedList[i]);
        }
    }

    // @return {int} the next element in the iteration
    int next() {
        auto result = m_stack.top().getInteger();
        m_stack.pop();
        return result;
    }

    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        while(!m_stack.empty() && !m_stack.top().isInteger()) {
            auto list = m_stack.top().getList();
            m_stack.pop();
            for(int i = list.size() - 1; i > - 1; --i) {
                m_stack.push(list[i]);
            }
        }
        return !m_stack.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */