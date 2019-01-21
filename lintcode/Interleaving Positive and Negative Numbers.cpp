class Solution {
public:
    void rerange(vector<int>& A) {
        // write your code here
        int len = A.size();
        if (len <= 1) {
            return;
        }
        int pos = 0;
        int neg = 0;
        for (int i = 0; i < len; i++) {
            if (A[i] < 0) {
                neg++;
            } else {
                pos++;
            }
        }
        int posind = 1;
        int negind = 0;
        if (neg < pos) {
            posind = 0;
            negind = 1;
        }
        while (posind < len && negind < len) {
            while (posind < len && A[posind] > 0) {
                posind += 2;
            }
            while (negind < len && A[negind] < 0) {
                negind += 2;
            }
            if (posind < len && negind < len) {
                swap(A[posind], A[negind]);
                posind += 2;
                negind += 2;
            }
        }
   }
};
