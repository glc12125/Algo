class RandomizedSet {
private:
    std::unordered_map<int, int> m_valueIndexes;
    std::vector<int> m_values;

public:
    RandomizedSet() {
        // do intialization if necessary
    }

    /*
     * @param val: a value to the set
     * @return: true if the set did not already contain the specified element or false
     */
    bool insert(int val) {
        if(m_valueIndexes.count(val)) return false;
        m_valueIndexes[val] = m_values.size();
        m_values.push_back(val);
        return true;
    }

    /*
     * @param val: a value from the set
     * @return: true if the set contained the specified element or false
     */
    bool remove(int val) {
        if(m_valueIndexes.count(val) == 0) return false;
        auto index = m_valueIndexes[val];
        std::swap(m_values[index], m_values.back());
        m_values.pop_back();
        return true;
    }

    /*
     * @return: Get a random element from the set
     */
    int getRandom() {
        int randomIndex = (int)std::rand() % m_values.size();
        return m_values[randomIndex];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param = obj.insert(val);
 * bool param = obj.remove(val);
 * int param = obj.getRandom();
 */