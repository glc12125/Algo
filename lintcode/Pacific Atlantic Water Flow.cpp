class Solution {
private:
    int m_xMoves[4] = {-1, 0, 1, 0};
    int m_yMoves[4] = {0, 1, 0, -1};

    struct ResultType {
        bool m_canReachPacific;
        bool m_canReachAtlantic;
        ResultType () = default;
        ResultType(bool pacific, bool atlantic) : m_canReachPacific(pacific), m_canReachAtlantic(atlantic) {}
    };

    bool isValidMove(int i, int j, int rowSize, int colSize) {
        return (0 <= i && i < rowSize && 0 <= j && j < colSize);
    }

    int getKey(int i, int j, int colSize) {
        return i * colSize + j;
    }

    ResultType dfs(vector<vector<int>> &matrix, int i, int j, unordered_set<int>& visited) {
        bool canReachPacific = false;
        bool canReachAtlantic = false;
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        if(i == 0 || j == 0) canReachPacific = true;
        if(j == colSize - 1 || i == rowSize - 1) canReachAtlantic = true;

        ResultType result(canReachPacific, canReachAtlantic);
        int key = getKey(i, j, colSize);
        visited.insert(key);
        for(int k = 0; k < 4; ++k) {
            int nextI = i + m_xMoves[k];
            int nextJ = j + m_yMoves[k];
            if(!isValidMove(nextI, nextJ, rowSize, colSize)) continue;
            if(matrix[nextI][nextJ] > matrix[i][j]) continue;
            if(visited.count(getKey(nextI, nextJ, colSize))) continue;
            auto trialResult = dfs(matrix, nextI, nextJ, visited);
            result.m_canReachPacific = result.m_canReachPacific || trialResult.m_canReachPacific;
            result.m_canReachAtlantic = result.m_canReachAtlantic || trialResult.m_canReachAtlantic;
            if(result.m_canReachAtlantic && result.m_canReachPacific) {break;}
        }
        visited.erase(key);

        return result;
    }
public:
    /**
     * @param matrix: the given matrix
     * @return: The list of grid coordinates
     */
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix) {
        int rowSize = matrix.size();
        if(rowSize == 0) return {{}};
        int colSize = matrix[0].size();
        if(colSize == 0) return {{}};

        vector<vector<int>> result;
        unordered_set<int> visited;
        for(int i = 0; i < rowSize; ++i) {
            for(int j = 0; j < colSize; ++j) {
                const auto& temp = dfs(matrix, i, j, visited);
                if(temp.m_canReachPacific && temp.m_canReachAtlantic) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};