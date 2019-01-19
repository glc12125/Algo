const int MAXN = 305;

class Solution {
private:
    vector<pair<int, int>> bikes, persons;
    bool vis_boy[MAXN], vis_girl[MAXN];
    int boy_exp[MAXN], girl_exp[MAXN];
    int match[MAXN], slack[MAXN];
    int love[MAXN][MAXN];
    int N;
    bool dfs(int girl){
        vis_girl[girl] = true;

        for (int i = 0; i < N; i++) {
            if (vis_boy[i]) {
                continue;
            }

            int gap = boy_exp[i] + girl_exp[girl] - love[girl][i];

            if (gap == 0) {
                vis_boy[i] = true;

                if (match[i] == -1 || dfs(match[i])) {
                    match[i] = girl;
                    return true;
                }
            }else{
                slack[i] = min(slack[i], gap);
            }
        }
        return false;
    }

    void initial(vector<vector<int>> &matrix){
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 1)
                    persons.push_back({i, j});
                if (matrix[i][j] == 2)
                    bikes.push_back({i, j});
            }
        }
        N = (int)persons.size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                love[i][j] = -abs(persons[i].first - bikes[j].first)
                - abs(persons[i].second - bikes[j].second);
            }
        }

        for (int i = 0; i < N; i++) {
            girl_exp[i] = love[i][0];
            for (int j = 1; j < N; j++) {
                girl_exp[i] = max(girl_exp[i], love[i][j]);
            }
        }

        fill(boy_exp, boy_exp + N, 0);
        fill(match, match + N, -1);
    }

    int KM(){

        for (int i = 0; i < N; i++) {

            fill(slack, slack + N, INT_MAX);

            while (true) {
                fill(vis_boy, vis_boy + N, false);
                fill(vis_girl, vis_girl + N, false);
                if (dfs(i)) {
                    break;
                }

                int d = INT_MAX;
                for (int i = 0; i < N; i++) {
                    if (!vis_boy[i]) {
                        d = min(slack[i], d);
                    }
                }
                for (int i = 0; i < N; i++) {
                    if (vis_girl[i]) {
                        girl_exp[i] -= d;
                    }

                    if (vis_boy[i]) {
                        boy_exp[i] += d;
                    }else{
                        slack[i] -= d;
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < N; i++) {
            res += love[match[i]][i];
        }
        return abs(res);
    }
public:

    int optimalMatch(vector<vector<int>> &matrix) {
        // Write your code here
        initial(matrix);
        return KM();
    }

};