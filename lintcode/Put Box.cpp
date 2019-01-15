class Solution {
public:
    /**
     * @param box: the boxes
     * @param position: the positions
     * @return:  the maximum number of boxes you can put in
     */
    int putBox(vector<int> &box, vector<int> &position) {
        int bLen = box.size();
        if(bLen == 0) return 0;
        int pLen = position.size();
        if(pLen == 0) return 0;

        vector<vector<int>> dp(bLen + 1, vector<int>(pLen + 1, 0));
        for(int i = 1; i <= bLen; ++i) {
            for(int j = 1; j <= pLen; ++j) {
                if(box[i-1] <= position[j-1]) {
                    dp[i][j] = std::max(dp[i-1][j-1] + 1, std::max(dp[i-1][j], dp[i][j-1]));
                } else {
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[bLen][pLen];
    }
};