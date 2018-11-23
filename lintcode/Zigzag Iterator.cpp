class ZigzagIterator {
private:
    int m_index;
    vector<int> m_container;
public:
    /*
    * @param v1: A 1d vector
    * @param v2: A 1d vector
    */ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int len1 = v1.size();
        int len2 = v2.size();
        m_index = 0;
        if(len1 == 0 && len2 == 0) return;
        if(len1 == 0) copy(v2.begin(), v2.end(), back_inserter(m_container));
        else if(len2 == 0) copy(v1.begin(), v1.end(), back_inserter(m_container));
        else{
            int chooseFrom = 0; // 0 means from v1, 1 means from v2
            int i = 0;
            int j = 0;
            while(i < len1 || j < len2) {
                if(chooseFrom == 0) {
                    m_container.push_back(v1[i++]);
                } else {
                    m_container.push_back(v2[j++]);
                }
                int nextChooseFrom = (chooseFrom + 1) % 2;
                if(nextChooseFrom == 0 && i < len1) chooseFrom = nextChooseFrom;
                else if(nextChooseFrom == 1 && j < len2) chooseFrom = nextChooseFrom;
            }
        }
    }

    /*
     * @return: An integer
     */
    int next() {
        return m_container[m_index++];
    }

    /*
     * @return: True if has next
     */
    bool hasNext() {
        return m_index < m_container.size();
    }
};


// O(1) space
class ZigzagIterator {
private:
    int m_chooseFrom;
    vector<int>::iterator m_begin[2];
    vector<int>::iterator m_end[2];
public:
    /*
    * @param v1: A 1d vector
    * @param v2: A 1d vector
    */ZigzagIterator(vector<int>& v1, vector<int>& v2) : m_chooseFrom(0) {
        m_begin[0] = v1.begin();
        m_begin[1] = v2.begin();
        m_end[0] = v1.end();
        m_end[1] = v2.end();
    }

    /*
     * @return: An integer
     */
    int next() {
        int value;
        if(m_begin[0] == m_end[0]) {
            value = *m_begin[1]++;
        } else if (m_begin[1] == m_end[1]) {
            value = *m_begin[0]++;
        } else {
            value = *m_begin[m_chooseFrom]++;
            m_chooseFrom = (m_chooseFrom + 1) % 2;
        }
        return value;
    }

    /*
     * @return: True if has next
     */
    bool hasNext() {
        return m_begin[0] != m_end[0] || m_begin[1] != m_end[1];
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator solution(v1, v2);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */