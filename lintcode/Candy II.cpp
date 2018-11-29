class Solution {
public:
    /**
     * @param ratings: rating value of each child
     * @return: Return the minimum candies you must give.
     */
    int candyII(vector<int> &ratings) {
        int len = ratings.size();
        vector<int> v(len, 1);
        for (int i = 1; i < len; i++) {
            if (ratings[i] == ratings[i - 1])
                v[i] = v[i - 1];
            else if (ratings[i] > ratings[i - 1])
                v[i] = v[i - 1] + 1;
        }
        for (int i = len - 2; i >= 0; i--) {
            if (ratings[i] == ratings[i + 1])
                v[i] = v[i + 1];
            else if (ratings[i] > ratings[i + 1])
                v[i] = max(v[i], v[i + 1] + 1);
        }
        int ans = 0;
        for (auto & val : v)
            ans += val;
        return ans;
    }
};