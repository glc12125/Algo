class TwoSum {
private:
    std::unordered_map<int, int> m_counter;
public:
    /**
     * @param number: An integer
     * @return: nothing
     */
    void add(int number) {
        ++m_counter[number];
    }

    /**
     * @param value: An integer
     * @return: Find if there exists any pair of numbers which sum is equal to the value.
     */
    bool find(int value) {
        for(auto item : m_counter) {
            int other = value - item.first;
            if(other == item.first && item.second > 1) return true;
            if(other != item.first && m_counter.count(other) > 0) return true;
        }
        return false;
    }
};