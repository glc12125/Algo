class Solution {
public:
    /*
     * @param envelopes: a number of envelopes with widths and heights
     * @return: the maximum number of envelopes
     */
    int maxEnvelopesDP(vector<pair<int, int>>& envelopes) {
        // write your code here
        int len = envelopes.size();
        if(len < 2) return len;

        sort(envelopes.begin(), envelopes.end());

        vector<int> dp(len);
        int maxCount = 0;
        for(int i = 0; i < len; ++i) {
            dp[i] = 1;
            for(int j = i - 1; j > -1; --j) {
                if(envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }

            maxCount = std::max(maxCount, dp[i]);
        }

        return maxCount;
    }

    int firstGTEenvelope(const vector<pair<int, int>>& prevNums, const pair<int, int>& target) {
        int i = 0;
        int j = prevNums.size() - 1;
        while(i + 1 < j) {
            int mid = i + (j - i) / 2;
            if(prevNums[mid].first < target.first && prevNums[mid].second < target.second) i = mid;
            else j = mid;
        }

        if(prevNums[i].first >= target.first || prevNums[i].second >= target.second) return i;
        if(prevNums[j].first >= target.first || prevNums[j].second >= target.second) return j;
        return 1;
    }

    struct PairCompare{
        bool operator()(const pair<int,int>&x, const pair<int, int>&y) const {
          return x.first != y.first ? x.first < y.first : x.second > y.second;
        }
    };

    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int len = envelopes.size();
        if(len < 2) return len;

        vector<pair<int, int>> prevEnvelopes(len + 1, pair<int, int>(INT_MAX, INT_MAX));
        prevEnvelopes[0].first = INT_MIN;
        prevEnvelopes[0].second = INT_MIN;

        sort(envelopes.begin(), envelopes.end(), PairCompare());
        for(int i = 0; i < len; ++i) {
            int pos = firstGTEenvelope(prevEnvelopes, envelopes[i]);
            prevEnvelopes[pos] = envelopes[i];
        }

        for(int i = len; i > 0; --i) {
            if(prevEnvelopes[i].first != INT_MAX && prevEnvelopes[i].second != INT_MAX) return i;
        }
        return 0;
    }
};