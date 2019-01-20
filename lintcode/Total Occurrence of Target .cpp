class Solution {
public:
    /**
     * @param A: A an integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int totalOccurrence(vector<int> &A, int target) {
        int len = A.size();
        if(len == 0) return 0;
        int start = 0;
        int end = len - 1;

        // find the left most
        int l = 0;
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if(A[mid] >= target) {
                end = mid;
            } else {
                start = mid;
            }
        }

        if(A[start] == target) {
            l = start;
        } else if(A[end] == target) {
            l = end;
        } else {
            return 0;
        }

        start = 0;
        end = len - 1;

        int r = end;
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if(A[mid] <= target) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if(A[end] == target) {
            r = end;
        } else if(A[start] == target) {
            r = start;
        }

        return r - l + 1;
    }
};


// Use binary search twice
int totalOccurrence(vector<int> &A, int target) {
    if (A.size() == 0) {
        return 0;
    }
    int left_bound = findFirstGTE(A, target);
    if (left_bound == -1 || A[left_bound] != target) {
        return 0;
    }
    int right_bound = findFirstGTE(A, target + 1);
    if (right_bound == -1) {
        return A.size() - left_bound;
    }
    return right_bound - left_bound;
}

int findFirstGTE(vector<int> &A, int target) {
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