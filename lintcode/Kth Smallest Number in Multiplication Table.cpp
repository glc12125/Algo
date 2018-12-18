class Solution {
private:
    int lessEqual(int r, int c, int target) {
        int res = 0;
        for (int i = 1; i <= r; ++i)
            res += min(c, target/i);
        return res;
    }
public:
    /**
     * @param m: a integer
     * @param n: a integer
     * @param k: a integer
     * @return: return a integer
     */
    int findKthNumber(int m, int n, int k) {
        // binary search
        int l = 1;
        int r = m * n;
        while (l + 1 < r) {
            int mid = (r - l) / 2 + l;
            if (lessEqual(m, n, mid) >= k)
                r = mid;
            else
                l = mid;
        }

        if (lessEqual(m, n, l) == k) return l;
        else return r;
    }
};