class Solution {
public:
    /**
     * @param moves: a sequence of its moves
     * @return: if this robot makes a circle
     */
    bool judgeCircle(string &moves) {
        int L = 0;
        int U = 0;
        for(auto c : moves) {
            if(c == 'L') ++L;
            if(c == 'R') --L;
            if(c == 'U') ++U;
            if(c == 'D') --U;
        }

        if(L == 0 && U == 0) return true;
        else return false;
    }
};