class Solution {
private:
    int m_xMoves[2] = {0, 1};
    int m_yMoves[2] = {1, 0};
    
    bool isValid(int rowSize, int colSize, int i, int j) {
        return (i < rowSize && j < colSize);
    }
    
    int getKey(int colSize, int i, int j) {
        return i * colSize + j;
    }
    
    struct Element {
        int m_x;
        int m_y;
        int m_val;
        Element () = default;
        Element(int x, int y, int val) : m_x(x), m_y(y), m_val(val) {}
    };
    
    struct ValueGreater{
        bool operator()(const Element& e1, const Element& e2) const {
            return e1.m_val > e2.m_val;
        }
    };
    
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: An integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int rowSize = matrix.size();
        if(rowSize == 0) return -1;
        int colSize = matrix[0].size();
        if(colSize == 0) return - 1;
        
        if(k > rowSize * colSize) return -1;
        std::priority_queue<Element, std::vector<Element>, ValueGreater > orderedContainer;
        std::unordered_set<int> visited;
        
        orderedContainer.push(Element(0, 0, matrix[0][0]));
        visited.insert(getKey(colSize, 0, 0));
        
        for(int i = 0; i < k - 1; ++i) {
            auto curr = orderedContainer.top();
            orderedContainer.pop();
             for(int j = 0; j < 2; ++j) {
                auto nextX = curr.m_x + m_xMoves[j];
                auto nextY = curr.m_y + m_yMoves[j];
                if(!isValid(rowSize, colSize, nextX, nextY) || visited.count(getKey(colSize, nextX, nextY))) continue;
                auto next = Element(nextX, nextY, matrix[nextX][nextY]);
                orderedContainer.push(next);
                visited.insert(getKey(colSize, nextX, nextY));
             }
        }
        
        return orderedContainer.top().m_val;
    }
};