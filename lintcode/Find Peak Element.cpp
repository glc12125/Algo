class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> &A) {
        int start = 1;
        int end = A.size() - 2; // 1.答案在之间，2.不会出界
        while(start + 1 <  end) {
            int mid = (start + end) / 2;
            if(A[mid] < A[mid - 1]) {
                end = mid;
            } else if(A[mid] < A[mid + 1]) {
                start = mid;
            } else {
                start = mid; // Or end = mid, or just return mid
            }
        }
        if(A[start] < A[end]) {
            return end;
        } else {
            return start;
        }
    }
};
