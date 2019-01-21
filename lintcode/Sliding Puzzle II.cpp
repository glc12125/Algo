class Solution {
private:
    int m_xMoves[4] = {-1, 0, 1, 0};
    int m_yMoves[4] = {0, 1, 0, -1};

    bool isValidMove(int x, int y, int w, int h) {
        return (0 <= x && x < h && 0 <= y && y < w);
    }

    string matrixToString(const vector<vector<int>> & state) {
        string result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result += to_string(state[i][j]);
            }
        }
        return result;
    }

    vector<string> getNext(const string& state, int w, int h) {
        int zeroIndex = state.find('0');
        int x = zeroIndex / 3;
        int y = zeroIndex % 3;

        vector<string> states;
        for(int i = 0; i < 4; ++i) {
            int nextX = x + m_xMoves[i];
            int nextY = y + m_yMoves[i];
            if(!isValidMove(nextX, nextY, w, h)) {continue;}

            string nextState(state);
            nextState[x * 3 + y] = nextState[nextX * 3 + nextY];
            nextState[nextX * 3 + nextY] = '0';
            states.emplace_back(nextState);
        }

        return states;
    }
public:
    /**
     * @param init_state: the initial state of chessboard
     * @param final_state: the final state of chessboard
     * @return: return an integer, denote the number of minimum moving
     */
    int minMoveStep(vector<vector<int>> &init_state, vector<vector<int>> &final_state) {
        int w = init_state.size();
        if(w == 0) return -1;
        int h = init_state[0].size();
        if(h == 0) return -1;

        auto start = matrixToString(init_state);
        auto target = matrixToString(final_state);

        queue<string> q;
        unordered_set<string> visited;
        q.push(start);
        visited.insert(start);

        int minStep = 0;
        while(!q.empty()) {
            int len = q.size();
            while(len > 0) {
                auto curr = q.front();
                q.pop();
                if(curr == target) {
                    return minStep;
                }

                for(const auto& next : getNext(curr, w, h)) {
                    if(visited.count(next)) continue;
                    visited.insert(next);
                    q.push(next);
                }

                --len;
            }
            ++minStep;
        }
        return -1;
    }
};