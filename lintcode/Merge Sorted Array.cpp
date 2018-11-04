class Solution {
public:
    /*
     * @param A: sorted integer array A which has m elements, but size of A is m+n
     * @param m: An integer
     * @param B: sorted integer array B which has n elements
     * @param n: An integer
     * @return: nothing
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        if(n == 0) return;

        int index = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while(i > -1 && j > -1 && index > -1) {
            if(A[i] > B[j]) {
                A[index--] = A[i--];
            } else {
                A[index--] = B[j--];
            }
        }

        while(i > -1 && index > -1) A[index--] = A[i--];
        while(j > -1 && index > -1) A[index--] = B[j--];
    }
};