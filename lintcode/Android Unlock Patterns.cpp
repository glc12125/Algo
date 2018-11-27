class Solution {
private:

    bool isValidChoice(const vector<vector<bool>>& chosen, int lastI, int lastJ, int i, int j) {
        if(lastI == -1 && lastJ == -1) return true;
        int dx = abs(lastI-i);
        int dy = abs(lastJ-j);
        if((dx == 2 && dy == 0) || (dx == 0 && dy == 2) || (dx == 2 && dy == 2)) return chosen[(i + lastI)/2][(j + lastJ)/2];
        else return true;
        //if(abs(lastI - i) > 1 && abs(lastJ - j) > 1) return chosen[1][1];
        //if(abs(lastI - i) > 1) return chosen[(i + lastI)/2][j] && chosen[(i + lastI)/2][lastJ];
        //if(abs(lastJ - j) > 1) return chosen[i][(j + lastJ)/2] && chosen[lastI][(j + lastJ)/2];
    }

    void dfs(vector<vector<bool>>& chosen, int lastI, int lastJ, int count, int m, int n, int& total) {
        if(m <= count && count <= n) {
            ++total;
        }
        if(count >= n) {
            return;
        }

        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(chosen[i][j]) continue;
                if(!isValidChoice(chosen, lastI, lastJ, i, j)) continue;
                chosen[i][j] = true;
                dfs(chosen, i, j, count + 1, m, n, total);
                chosen[i][j] = false;
            }
        }
    }
public:
    /**
     * @param m: an integer
     * @param n: an integer
     * @return: the total number of unlock patterns of the Android lock screen
     */
    int numberOfPatterns(int m, int n) {
        vector<vector<bool>> chosen(3, vector<bool>(3, false));
        int total = 0;
        dfs(chosen, -1, -1, 0, m, n, total);
        return total;
    }
};