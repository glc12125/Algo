class Solution {
public:
    /**
     * @param A: An array of integers
     * @return: A long integer
     */
    long long permutationIndex(vector<int> &A) {
        int len = A.size();
        long long result = 0;
        long long permutation = 1;

        for(int i = len - 2; i > -1; --i) {
            int smallerThanIcount = 0;
            for(int j = i + 1; j < len; ++j) {
                if(A[j] < A[i]) {
                    ++smallerThanIcount;
                }
            }

            result += smallerThanIcount * permutation;
            permutation *= (len - i);
        }

        return result + 1;
    }
};