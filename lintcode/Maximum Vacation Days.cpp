class Solution {
private:
    int getMaxLeaves(const vector<vector<int>>& dp, int week, int city, const vector<vector<int>> &flights) {
        int maxLeaves = dp[city][week];
        int cityNum = flights.size();
        for(int i = 0; i < cityNum; ++i) {
            if(flights[city][i] == 1 && i != city) {
               maxLeaves = std::max(maxLeaves, dp[i][week]);
            }
        }
        return maxLeaves;
    }
public:
    /**
     * @param flights: the airline status from the city i to the city j
     * @param days: days[i][j] represents the maximum days you could take vacation in the city i in the week j
     * @return: the maximum vacation days you could take during K weeks
     */
    int maxVacationDays(vector<vector<int>> &flights, vector<vector<int>> &days) {
        int N = days.size();
        if(N == 0) return 0;
        int K = days[0].size();
        if(K == 0) return 0;

        vector<vector<int>> dp(N, vector<int>(K, 0));
        for(int n = 0; n < N; ++n) {
            dp[n][K-1] = days[n][K-1];
        }

        for(int week = K - 2; week >= 0; --week) {
            for(int city = 0; city < N; ++city) {
                dp[city][week] = days[city][week] + getMaxLeaves(dp, week + 1, city, flights);
            }
        }

        return getMaxLeaves(dp, 0, 0, flights);
    }
};