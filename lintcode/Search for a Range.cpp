class Solution {
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: a list of length 2, [index1, index2]
     */
    vector<int> searchRange(vector<int> &A, int target) {
        int size = A.size();
        if(size == 0) return {-1, -1};
        int start = 0;
        int end = size - 1;
        int mid;
        while(start + 1 < end) {
            mid = (start + end) / 2;
            if(A[mid] < target) start = mid;
            else end = mid;
        }
        int rangeStart = -1;
        if(A[end] == target) rangeStart = end;
        if(A[start] == target) rangeStart = start;
        
        start = 0;
        end = size - 1;
        while(start + 1 < end) {
            mid = (start + end) / 2;
            if(A[mid] > target) end = mid;
            else start = mid;
        }
        int rangeEnd = -1;
        if(A[start] == target) rangeEnd = start;
        if(A[end] == target) rangeEnd = end;
        
        return {rangeStart, rangeEnd};
    }
};