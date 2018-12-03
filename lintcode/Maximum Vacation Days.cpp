// It's easier to start from last week to first week, because we dont need to record if previous week
// for certain city can be reached
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

// From start to end
/*
dp[city][week] the max vacation days in city on week。

initialization: dp[city][0] = days[city][0] if flights[0][city] == 1 。starting city can be non-zero,
but must have a flight from 0

dp[city][week] = days[city][week] + maxVacation_of_last_week
*/
class Solution {
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
        vector<vector<bool>> canTravel(N, vector<bool>(K, false));

        dp[0][0] = days[0][0];
        canTravel[0][0] = true;
        for(int n = 1; n < N; ++n) {
            if(flights[0][n] == 1){
                dp[n][0] = days[n][0];
                canTravel[n][0] = true;
            }
        }

        for(int week = 1; week < K; ++week) {
            for(int city = 0; city < N; ++city) {
                // If stay in the same city in consequtive weeks, we don't need to check flight,
                // just check if previous city on previous week is travellable
                if(canTravel[city][week-1]) {
                    dp[city][week] =  days[city][week] + dp[city][week-1];
                    canTravel[city][week] = true;
                }
                for(int prevCity = 0; prevCity < N; ++prevCity) {
                    if(flights[prevCity][city] == 1 && canTravel[prevCity][week-1]) {
                        canTravel[city][week] = true;
                        dp[city][week] = std::max(dp[city][week], days[city][week] + dp[prevCity][week-1]);
                    }
                }
            }
        }

        int maxLeaves = 0;
        for(int i = 0; i < N; ++i) {
            maxLeaves = std::max(maxLeaves, dp[i][K-1]);
        }
        return maxLeaves;
    }
};

// Memoisation search
class Solution {
private:
    void dfs(const vector<vector<int>> &flights, const vector<vector<int>> &days, int week, int city, int& maxLeaves, vector<vector<int>> & mem) {

        if(mem[city][week] != -1) return;

        int N = days.size();
        int K = days[0].size();
        int curVacation = days[city][week];
        int nextVacation = 0;

        // Calculate mem[city][week+1] to stay in the same city
        if(week < K - 1) {
            dfs(flights, days, week + 1, city, maxLeaves, mem);
            nextVacation = mem[city][week+1];
        }

        // Calculate mem[nextCity][week+1] to stay in another city
        if(week < K - 1) {
            for(int nextCity = 0; nextCity < N; ++nextCity) {
                if(flights[city][nextCity] == 1) {
                    dfs(flights, days, week + 1, nextCity, maxLeaves, mem);
                    nextVacation =std::max(nextVacation, mem[nextCity][week + 1]);
                }
            }
        }

        curVacation += nextVacation;
        maxLeaves = std::max(maxLeaves, curVacation);
        mem[city][week] = curVacation;
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

        vector<vector<int>> mem(N, vector<int>(K, -1));

        int maxLeaves = 0;
        dfs(flights, days, 0, 0, maxLeaves, mem);

        for(int i = 0; i < N; ++i) {
            if(flights[0][i] == 1) {
                dfs(flights, days, 0, i, maxLeaves, mem);
            }
        }

        return maxLeaves;
    }
};