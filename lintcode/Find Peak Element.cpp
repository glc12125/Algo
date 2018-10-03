class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> &A) {
        int size = A.size();
        int start = 0;
        int end = size - 1;
        int mid;
        while(start < end) {
            mid = (start + end) / 2;
            if(A[mid-1] < A[mid] && A[mid+1] < A[mid]) return mid;
            if(A[mid-1] > A[mid]) end = mid - 1;
            else if( A[mid+1] > A[mid]) start = mid + 1;
        }
        
    }
};