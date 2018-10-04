class Solution {
public:
    /**
     * @param A: A an integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int totalOccurrence(vector<int> &A, int target) {
        if(A.size() == 0) return 0;
        int start = 0;
        int end = A.size() - 1;
        int count = 0;
        int pivot;
        while(start < end) {
            pivot = start;
            if(A[pivot] == target) ++count;
            if(A[pivot] > target) end = pivot - 1;
            else start = pivot + 1;
        }

        if(A[start] == target) ++count;
        return count;
    }
};