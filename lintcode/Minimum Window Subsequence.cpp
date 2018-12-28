class Solution {
public:
    /**
     * @param S: a string
     * @param T: a string
     * @return: the minimum substring of S
     */
    string minWindow(string &S, string &T) {
        int len = S.size();
        int tLen = T.size();
        if(tLen > len) return "";

        int maxLeft = -1;
        int minRight = -1;
        int minLen = INT_MAX;
        int index = 0;
        int max = len - tLen;
        while(index <= max) {
            int tIndex = 0;
            int left = -1;
            int right = -1;
            for(int i = index; i < len; ++i) {
                if(S[i] == T[tIndex]) {++tIndex;}
                if(left == -1 && tIndex == 1) {
                    left = i;
                    index = left + 1;
                }
                if(tIndex == tLen) {
                    right = i + 1;
                    break;
                }
            }
            if(left == -1 || right == -1) {
                break;
            }
            if(right - left < minLen) {
                maxLeft = left;
                minRight = right;
                minLen = right - left;
            }
        }

        if(maxLeft == -1 || minRight == -1) {
            return "";
        } else {
            return S.substr(maxLeft, minRight - maxLeft);
        }
    }
};