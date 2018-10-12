class Solution {
public:
    /**
     * @param A: an integer ratated sorted array and duplicates are allowed
     * @param target: An integer
     * @return: a boolean 
     */
    bool search(vector<int> &A, int target) {
        if(A.size() == 0) return false;
        int start = 0;
        int end = A.size() - 1;
        int mid;
        while(start + 1 < end) {
            mid = (start + end) / 2;
            if(target == A[mid]) return true;
            if (A[start] < A[mid]) {
                // left-hand side
                if (A[start] <= target && target <= A[mid]) {
                    end = mid;
                } else {
                    start = mid;
                }
            } else if (A[start] > A[mid]){
                // right-hand side
                if (A[mid] <= target && target <= A[end]) {
                    start = mid;
                } else {
                    end = mid;
                }
            } else {
                ++start;
            }
        }
        
        //std::cout << "start: " << A[start] << ", end: " << A[end] << "\n";
        if(A[start] == target) return true;
        if(A[end] == target) return true;
        return false;
    }
};