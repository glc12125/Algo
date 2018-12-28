// Time O(NlogMax)
class Solution {
public:
    /**
     * @param stations: an integer array
     * @param k: an integer
     * @return: the smallest possible value of D
     */
    double minmaxGasDist(vector<int> &stations, int k) {
        double left = 0, right = 1e8;
        while (right - left > 1e-6) {
            double mid = left + (right - left) / 2;
            if (helper(stations, k, mid)) right = mid;
            else left = mid;
        }
        return left;
    }

    bool helper(vector<int>& stations, int k, double mid) {
        int cnt = 0, n = stations.size();
        for (int i = 0; i < n - 1; ++i) {
            cnt += (stations[i + 1] - stations[i]) / mid;
        }
        return cnt <= k;
    }
};