// Time O(NlogN), K is the number of edges, space O(N)
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        vector<vector<int>> edges;
        int minx = INT_MAX;
        int miny = INT_MAX;
        int maxx = INT_MIN;
        int maxy = INT_MIN;
        int sum = 0;
        for(auto &a:rectangles) {
            edges.push_back({a[0], 1, a[1], a[3]});
            edges.push_back({a[2], -1, a[1], a[3]});
            sum += (a[2] - a[0])*(a[3] - a[1]);
            minx = min(minx, a[0]);
            maxx = max(maxx, a[2]);
            miny = min(miny, a[1]);
            maxy = max(maxy, a[3]);
        }
        if(sum != (maxy-miny)*(maxx-minx)) return false;

        sort(edges.begin(), edges.end());
        set<pair<int,int>> st;
        for(auto &a : edges) {
            if(a[1] < 0) st.erase({a[2],a[3]});
            else {
                auto it = st.lower_bound({a[2],a[3]});
                if(it != st.end() && it->first < a[3]) return false;
                if(it != st.begin() && (--it)->second > a[2]) return false;
                st.insert({a[2], a[3]});
            }
        }
        return true;
    }
};

// Time O(N^2), space O(1)
class Solution {
public:
    /**
     * @param rectangles: N axis-aligned rectangles
     * @return: if they all together form an exact cover of a rectangular region
     */
    bool isRectangleCover(vector<vector<int>> &rectangles) {
        int rmin, rmax, cmin, cmax;
        rmin = cmin = INT_MAX;
        rmax = cmax = INT_MIN;

        int area = 0;
        for (int i=0; i<int(rectangles.size()); i++) {
            auto & r = rectangles[i];
            for (int j=0; j<i; j++) {
                if (overlap(r, rectangles[j])) return false;
            }
            rmin = min(rmin, r[0]);
            cmin = min(cmin, r[1]);
            rmax = max(rmax, r[2]);
            cmax = max(cmax, r[3]);
            area += (r[2] - r[0]) * (r[3] - r[1]);
        }
        return area == (cmax - cmin) * (rmax - rmin);
    }

private:
    bool overlap(vector<int> const & a, vector<int> const & b) {
        return !(a[0] >= b[2] || b[0] >= a[2] || a[1] >= b[3] || b[1] >= a[3]);
    }
};