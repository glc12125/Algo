class Solution {
public:
    /**
     * @param A: an integer array sorted in ascending order
     * @param target: An integer
     * @return: an integer
     */
    int closestNumber(vector<int> &A, int target) {
        int size = A.size();
        if(size == 0) return -1;
        int start = 0;
        int end = size - 1;
        int mid;
        while (start + 1 < end) {
            mid = (start + end) / 2;
            if(A[mid] == target) break;
            if(A[mid] > target) end = mid;
            else start = mid;
        }

        if(target == A[mid]) return mid;
        if(std::abs(A[start] - target) < std::abs(A[end] - target)) return start;
        else return end;
    }
};