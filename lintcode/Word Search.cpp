class Solution {
private:
    int m_rowMoves[4] = {-1, 0, 1, 0};
    int m_colMoves[4] = {0, 1, 0, -1};

    int getKey(int r, int c, int colSize) {
        return r * colSize + c;
    }

    bool isValidMove(int r, int c, int rowSize, int colSize) {
        return (0 <= r && r < rowSize && 0 <= c && c < colSize);
    }


    bool dfs(const vector<vector<char>> &board, int row, int col, const string& word, unordered_set<int>& visited, string& candidate) {
        if(candidate.size() == word.size()) {
            return candidate == word;
        }
        int lastIndex = candidate.size() - 1;
        if(candidate[lastIndex] != word[lastIndex]) return false;
        int rowSize = board.size();
        int colSize = board[0].size();
        for(int i = 0; i < 4; ++i) {
            int nextRow = row + m_rowMoves[i];
            int nextCol = col + m_colMoves[i];
            if(!isValidMove(nextRow, nextCol, rowSize, colSize)) continue;
            int key = getKey(nextRow, nextCol, colSize);
            if(visited.count(key)) continue;
            visited.insert(key);
            candidate += board[nextRow][nextCol];
            if(dfs(board, nextRow, nextCol, word, visited, candidate)) return true;
            candidate.pop_back();
            visited.erase(key);
        }

        return false;
    }
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char>> &board, string &word) {
        int rowSize = board.size();
        if(rowSize == 0) return false;
        int colSize = board[0].size();
        if(colSize == 0) return false;

        unordered_map<string, bool> memo;
        int targetLen = word.size();
        for(int i = 0; i < rowSize; ++i) {
            for(int j = 0; j < colSize; ++j) {
                string result(1, board[i][j]);
                unordered_set<int> visited;
                if(dfs(board, i, j, word, visited, result)) return true;
            }
        }

        return false;
    }
};