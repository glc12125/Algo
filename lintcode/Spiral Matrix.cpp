class Solution {
private:
    int m_xMoves[4] = {0, 1, 0, -1};
    int m_yMoves[4] = {1, 0, -1, 0};

    int getKey(int i, int j, int colSize) {
        return i * colSize + j;
    }

    bool isValidMove(int i, int j, int rowSize, int colSize) {
        return (0 <= i && i < rowSize && 0 <= j && j < colSize);
    }
public:
    /**
     * @param matrix: a matrix of m x n elements
     * @return: an integer list
     */
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int rowSize = matrix.size();
        if(rowSize == 0) return {};
        int colSize = matrix[0].size();
        if(colSize == 0) return {};

        int i = 0;
        int j = 0;
        int direction = 0;
        int maxIterCount = rowSize * colSize;
        vector<int> result;
        unordered_set<int> visited;
        for(int k = 0; k < maxIterCount; ++k) {
            result.push_back(matrix[i][j]);
            visited.insert(getKey(i, j, colSize));
            int nextI = i + m_xMoves[direction];
            int nextJ = j + m_yMoves[direction];

            if(!isValidMove(nextI, nextJ, rowSize, colSize) || visited.count(getKey(nextI, nextJ, colSize))) {
                direction = (direction + 1) % 4;
                nextI = i + m_xMoves[direction];
                nextJ = j + m_yMoves[direction];
            }

            i = nextI;
            j = nextJ;
        }
        return result;
    }
};

// DFS
class Solution {
private:
    int m_xMoves[4] = {0, 1, 0, -1};
    int m_yMoves[4] = {1, 0, -1, 0};

    int getKey(int i, int j, int colSize) {
        return i * colSize + j;
    }

    bool isValidMove(int i, int j, int rowSize, int colSize) {
        return (0 <= i && i < rowSize && 0 <= j && j < colSize);
    }

    void dfs(const vector<vector<int> > &matrix, int direction, int i, int j, unordered_set<int>& visited, vector<int>& result) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        result.push_back(matrix[i][j]);
        visited.insert(getKey(i, j, colSize));
        int nextI = i + m_xMoves[direction];
        int nextJ = j + m_yMoves[direction];
        if(!isValidMove(nextI, nextJ, rowSize, colSize) || visited.count(getKey(nextI, nextJ, colSize))) {
            direction = (direction + 1) % 4;
            nextI = i + m_xMoves[direction];
            nextJ = j + m_yMoves[direction];
        }
        if(isValidMove(nextI, nextJ, rowSize, colSize) && visited.count(getKey(nextI, nextJ, colSize)) == 0) {
            dfs(matrix, direction, nextI, nextJ, visited, result);
        }
    }
public:
    /**
     * @param matrix: a matrix of m x n elements
     * @return: an integer list
     */
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int rowSize = matrix.size();
        if(rowSize == 0) return {};
        int colSize = matrix[0].size();
        if(colSize == 0) return {};

        vector<int> result;
        unordered_set<int> visited;
        dfs(matrix, 0, 0, 0, visited, result);
        return result;
    }
};