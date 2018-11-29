class Solution {
public:
    /**
     * @param points: a 2D array
     * @return: the number of boomerangs
     */
    int numberOfBoomerangs(vector<vector<int>> &points) {
        auto s = points.size();

        int total = 0;
        for(int i = 0; i < s; ++i)
        {
            std::unordered_map<long, int> m;
            for(int j = 0; j < s; ++j)
            {
                if(i == j) continue;
                auto l = points[i];
                auto r = points[j];
                long dist = (l[0] - r[0]) * (l[0] - r[0])  + (l[1] - r[1]) * (l[1] - r[1]);
                ++m[dist];
            }
            for(auto it : m) total += it.second * (it.second - 1);
        }

        return total;
    }
};