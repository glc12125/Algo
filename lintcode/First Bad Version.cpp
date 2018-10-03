class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        long start = 1;
        long end = n;
        long mid;
        while(start < end) {
            mid = (start + end) / 2;
            if(SVNRepo::isBadVersion(mid)) {
                end = mid - 1;
            } else { start = mid + 1;}
        }
        if(SVNRepo::isBadVersion(start)) return start;
        else return end + 1;
    }
};