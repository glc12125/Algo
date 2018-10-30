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


// Use Stacks
class Vector2D {
private:
    std::stack<std::vector<int> > m_mainContainer;
    std::stack<int> m_workSpace;

    void addVector2DtoMain(vector<vector<int>>& vec2d) {
        int len = vec2d.size();
        for(int i = len - 1; i > -1; --i) {
            std::vector<int> vec(vec2d[i]);
            if(vec.empty()) continue;
            std::reverse(vec.begin(), vec.end());
            m_mainContainer.push(vec);
        }
    }

    void addVectorToBuffer() {
        if(m_mainContainer.empty()) return;
        auto line = m_mainContainer.top();
        m_mainContainer.pop();
        for(auto i : line) m_workSpace.push(i);
    }
public:
    Vector2D(vector<vector<int>>& vec2d) {
        addVector2DtoMain(vec2d);
    }

    int next() {
        auto result =  m_workSpace.top();
        m_workSpace.pop();
        return result;
    }

    bool hasNext() {
        if(m_workSpace.empty() && !m_mainContainer.empty()) addVectorToBuffer();
        return !m_workSpace.empty();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

