class Solution {
private:
    struct Element{
        int m_row;
        int m_col;
        int m_val;
        Element() : m_row(0), m_col(0), m_val(0) {}
        Element(int row, int col, int val) : m_row(row), m_col(col), m_val(val) {}
    };

    struct ElementCompare{
        bool operator()(const Element& e1, const Element& e2) const {
            return e1.m_val > e2.m_val;
        }
    };

    std::priority_queue<Element, std::vector<Element>, ElementCompare> m_q;
public:
    /**
     * @param arrays: k sorted integer arrays
     * @return: a sorted array
     */
    vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
        int rowLen = arrays.size();
        if(rowLen == 0) return {};
        for(int i = 0; i < rowLen; ++i) {
            int colLen = arrays[i].size();
            if(colLen == 0) continue;
            m_q.push(Element(i, 0, arrays[i][0]));
        }

        std::vector<int> mergedResult;
        while(!m_q.empty()) {
            const auto& element = m_q.top();
            mergedResult.push_back(element.m_val);
            if(element.m_col + 1 < arrays[element.m_row].size()) {
                m_q.push(Element(element.m_row, element.m_col + 1, arrays[element.m_row][element.m_col + 1]));
            }
            m_q.pop();
        }
        return mergedResult;
    }
};