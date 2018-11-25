class Solution {
public:
    #define MOD 1000000007
    /**
     * @param N: a integer
     * @return: return a integer
     */
    int numTilings(int N) {
        if (N < 0) {
            return 0;
        }

        // empty, lower_empty, upper_empty
        vector<vector<long long>> dp(3, vector<long long>(3, 0));
        dp[0][0] = 1;
        dp[1][0] = 1;

        for (int i = 2; i <= N; ++i) {
            /*
            for ithe column, there are three possible states
            1. empty 0
                     0, which means i - 1 has been filled full.
                     it can be acheived with the following situations:
                1) i - 1 is empty and add x
                                          x
                2) i - 2 is empty and add xx                 xy
                                          yy, note cannot be xy, because it has been taken care of by i - 1 empty
                3) i - 1 upper is filled and add  x
                                                 xx,
                4) i - 1 lower is filled and add xx
                                                  x
            2. upper x
                     0
                     it can be achieved with the following situations:
                1) i - 2 is empty and add xx
                                          x
                2) i - 1 lower is filled 0          xx
                                         x, and add
            3. lower 0
                     x
                    it can be achieved with the following situations:
                1) i - 2 is empty and add x
                                          xx
                2) i - 1 lower is filled x
                                         0, and add xx
            */
            dp[i%3][0] = (dp[(i-1)%3][0] + dp[(i-2)%3][0] + dp[(i-1)%3][1] + dp[(i-1)%3][2])%MOD;
            dp[i%3][1] = (dp[(i-2)%3][0] + dp[(i-1)%3][2])%MOD;
            dp[i%3][2] = (dp[(i-2)%3][0] + dp[(i-1)%3][1])%MOD;
        }

        return dp[N%3][0];
    }
};