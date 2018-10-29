class Vector2D {
private:
    int m_rowIndex;
    int m_colIndex;
    std::vector<vector<int> > * m_vec2d;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        m_rowIndex = 0;
        m_colIndex = 0;
        m_vec2d = &vec2d;
    }

    int next() {
        while((*m_vec2d)[m_rowIndex].size() == 0) {++m_rowIndex;}
        int result = (*m_vec2d)[m_rowIndex][m_colIndex];
        if(m_colIndex + 1 == (*m_vec2d)[m_rowIndex].size()) {
            ++m_rowIndex;
            m_colIndex = 0;
        } else {
            ++m_colIndex;
        }
        return result;
    }

    bool hasNext() {
        if(m_vec2d->empty()) return false;
        if(m_rowIndex == m_vec2d->size()) return false;
        if(m_colIndex == (*m_vec2d)[m_rowIndex].size()) {
            if(m_rowIndex == m_vec2d->size() - 1) return false;
        }
        return true;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */