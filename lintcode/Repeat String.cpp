class Solution {
public:
    /**
     * @param A: string A to be repeated
     * @param B: string B
     * @return: the minimum number of times A has to be repeated
     */
    int repeatedString(string &A, string &B) {
        int lenA = A.size();
        if(lenA == 0) return -1;
        int lenB = B.size();
        if(lenB == 0) return 1;

        int repeat = 0;
        string repeatedA;
        while(repeatedA.size() < B.size()) {
            repeatedA += A;
            ++repeat;
        }

        if(repeatedA.find(B) != string::npos) {
            return repeat;
        }

        repeatedA += A;
        ++repeat;
        if(repeatedA.find(B) != string::npos) {
            return repeat;
        }
        return -1;
    }
};

// Loop B instead
class Solution {
private:
    int match(const string& A, const string& B, int index) {
        int count = 1;
        for(int i = 0; i < B.size(); ++i) {
            if(index == A.size()) {
                ++count;
                index = 0;
            }
            if(A[index] != B[i]) return - 1;
            ++index;
        }
        return count;
    }
public:
    /**
     * @param A: string A to be repeated
     * @param B: string B
     * @return: the minimum number of times A has to be repeated
     */
    int repeatedString(string &A, string &B) {
        for(int i = 0; i < A.size(); ++i){
            int res = match(A, B, i);
            if(res != -1){
                return res;
            }
        }

        return -1;
    }
};