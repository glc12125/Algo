class ZigzagIterator2 {
private:
    using IterType = vector<int>::iterator;
    int m_k;
    int m_chooseFrom;
    vector<IterType> m_begin;
    vector<IterType> m_end;
public:
    /*
    * @param vecs: a list of 1d vectors
    */ZigzagIterator2(vector<vector<int>>& vecs) : m_k(vecs.size()), m_chooseFrom(0) {
        m_begin.resize(m_k);
        m_end.resize(m_k);
        for(int i = 0; i < m_k; ++i) {
            m_begin[i] = vecs[i].begin();
            m_end[i] = vecs[i].end();
        }
    }

    /*
     * @return: An integer
     */
    int next() {
        int value;
        while(m_begin[m_chooseFrom] == m_end[m_chooseFrom]) {
            m_chooseFrom = (m_chooseFrom + 1) % m_k;
        }
        value = *m_begin[m_chooseFrom]++;
        m_chooseFrom = (m_chooseFrom + 1) % m_k;
        return value;
    }

    /*
     * @return: True if has next
     */
    bool hasNext() {
        for(int i = 0; i < m_k; ++i) {
            if(m_begin[i] != m_end[i]) return true;
        }
        return false;
    }
};

// O(1) for hasNext()
class ZigzagIterator2 {
private:
    using IterType = vector<int>::iterator;
    int m_k;
    int m_chooseFrom;
    vector<IterType> m_begin;
    vector<IterType> m_end;
public:
    /*
    * @param vecs: a list of 1d vectors
    */ZigzagIterator2(vector<vector<int>>& vecs) : m_k(0), m_chooseFrom(0) {
        int len = vecs.size();
        for(int i = 0; i < len; ++i) {
            if(vecs[i].size()) {
                ++m_k;
                m_begin.push_back(vecs[i].begin());
                m_end.push_back(vecs[i].end());
            }
        }
    }

    /*
     * @return: An integer
     */
    int next() {
        int value = *m_begin[m_chooseFrom]++;
        if(m_begin[m_chooseFrom] == m_end[m_chooseFrom]) {
            m_begin.erase(m_begin.begin() + m_chooseFrom);
            m_end.erase(m_end.begin() + m_chooseFrom);
            --m_k;
            if(m_k > 0) m_chooseFrom = m_chooseFrom % m_k;
        } else {
            m_chooseFrom = (m_chooseFrom + 1) % m_k;
        }
        return value;
    }

    /*
     * @return: True if has next
     */
    bool hasNext() {
        return m_k > 0;
    }
};

/**
 * Your ZigzagIterator2 object will be instantiated and called as such:
 * ZigzagIterator2 solution(vecs);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */