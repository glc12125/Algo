class Solution {
public:
    /**
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target) {
        if(A.size() == 0) return -1;
        int start = 0;
        int end = A.size() - 1;
        int mid;
        while(start + 1 < end) {
            mid = (start + end) / 2;
            if(target == A[mid]) return mid;
            if (A[start] < A[mid]) {
                // left-hand side
                if (A[start] <= target && target <= A[mid]) {
                    end = mid;
                } else {
                    start = mid;
                }
            } else {
                // right-hand side
                if (A[mid] <= target && target <= A[end]) {
                    start = mid;
                } else {
                    end = mid;
                }
            }
        }
        
        //std::cout << "start: " << A[start] << ", end: " << A[end] << "\n";
        if(A[start] == target) return start;
        if(A[end] == target) return end;
        return -1;
    }
};