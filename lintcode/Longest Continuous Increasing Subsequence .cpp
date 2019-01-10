// Time O(N), space O(1)
class Solution {
public:
    /**
     * @param A: An array of Integer
     * @return: an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int> &A) {
        int len = A.size();
        if(len < 2) return len;

        vector<int> increaseLens(2, 0);
        vector<int> decreaseLens(2, 0);
        int result = INT_MIN;

        for(int i = 1; i <= len; ++i) {
            increaseLens[i%2] = 1;
            decreaseLens[i%2] = 1;

            if(i > 1) {
                if(A[i-1] > A[i-2]) {
                    increaseLens[i%2] += increaseLens[(i-1)%2];
                }

                if(A[i-1] < A[i-2]) {
                    decreaseLens[i%2] += decreaseLens[(i-1)%2];
                }
            }

            result = std::max(result, std::max(increaseLens[i%2], decreaseLens[i%2]));
        }

        return result;
    }
};
