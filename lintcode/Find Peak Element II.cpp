class Solution {
private:
    int findRowMax(const std::vector<int>& row, int& max) {
        max = INT_MIN;
        int j = 0;
        for(int i = 0; i < row.size(); ++i) {
            if(max < row[i]) {
                max = row[i];
                j = i;
            }
        }
        return j;
    }
public:
    /*
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int>> &A) {
        int n = A.size();
        if(n == 0) return {};
        int m = A[0].size();
        if(m == 0) return {};

        int lower = 0;
        int higher = n - 1;
        int mid;
        int rowMax;
        while(lower + 1 < higher) {
            mid = lower + (higher - lower) / 2;
            int colIndex = findRowMax(A[mid], rowMax);
            if(mid > 0 && rowMax <= A[mid-1][colIndex]) higher = mid;
            else if(mid < n - 1 && rowMax <= A[mid+1][colIndex] ) lower = mid;
            else if (mid > 0 && mid < n - 1 && rowMax >= A[mid-1][colIndex] && rowMax >= A[mid+1][colIndex]) return {mid, colIndex};
        }
        int rowMax2;
        int colIndex = findRowMax(A[lower], rowMax);
        int colIndex2 = findRowMax(A[higher], rowMax2);
        if(rowMax >= rowMax2) return {lower, colIndex};
        else return {higher, colIndex2};
    }
};