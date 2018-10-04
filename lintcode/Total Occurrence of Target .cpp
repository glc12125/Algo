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


// Use binary search twice
int totalOccurrence(vector<int> &A, int target) {
    if (A.size() == 0) {
        return 0;
    }
    int left_bound = greaterOrEqual(A, target);
    if (left_bound == -1 || A[left_bound] != target) {
        return 0;
    }
    int right_bound = greaterOrEqual(A, target + 1);
    if (right_bound == -1) {
        return A.size() - left_bound;
    }
    return right_bound - left_bound;
}

int greaterOrEqual(vector<int> &A, int target) {
    int left = 0, right = A.size() - 1;
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (A[mid] >= target) {
            right = mid;
        } else {
            left = mid;
        }
    }
    if (A[left] >= target) {
        return left;
    }
    if (A[right] >= target) {
        return right;
    }
    return -1;
}