class Solution {
public:
    /**
     * @param A: A positive integer which has N digits, A is a string
     * @param k: Remove k digits
     * @return: A string
     */
    string remove(string A, int pos) {
        return A.substr(0, pos) + A.substr(pos + 1);
    }

    string DeleteDigits(string A, int k) {
        if (A.length() == k) {
            return "";
        }

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < A.length(); j++) {
                if (j == A.length() - 1 || A[j + 1] < A[j]) {
                    A = remove(A, j);
                    break;
                }
            }
        }

        int i = 0;
        while (i < A.length() - 1 && A[i] == '0') {
            i++;
        }
        return A.substr(i, A.length() - i);
    }
};