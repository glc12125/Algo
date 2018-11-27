class Solution {
public:
    /**
     * @param points: n points on a 2D plane
     * @return: if there is such a line parallel to y-axis that reflect the given points
     */
    bool isReflected(vector<vector<int>> &points) {
        int len = points.size();
        if(len == 0) return true;
        if(len == 1) return false;

        unordered_map<int, vector<int> > yMapping;
        for(int i = 0; i < len; ++i) {
            yMapping[points[i][1]].push_back(points[i][0]);
        }

        int globabX = INT_MAX;
        for(auto i : yMapping) {
            auto& xElements = i.second;
            sort(xElements.begin(), xElements.end());
            int l = 0;
            int r = xElements.size() - 1;
            int sum = xElements[l++] + xElements[r--];
            while(l <= r) {
                if(xElements[l++] + xElements[r--] != sum) return false;
            }
            int mid = sum;
            if(globabX == INT_MAX) globabX = mid;
            else if(globabX != mid) return false;
        }
        return true;
    }
};