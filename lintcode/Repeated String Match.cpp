class Solution {
public:
    /**
     * @param A: a string
     * @param B: a string
     * @return: return an integer
     */
    int repeatedStringMatch(string &A, string &B) {
        int sizeA = A.size();
        for(int i = 0; i < sizeA; ++i) {
            int j = 0;
            while(A[(i + j)%sizeA] == B[j]) ++j;
            if (j == B.size()) return (i + j + sizeA - 1)/ sizeA;
        }
        return -1;
    }
};