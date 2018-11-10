class Solution {
public:
    /**
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        if(n == 0) return false;
        if(n == 1) return true;
        if(n == 2) return true;

        bool twoMove = true;
        bool oneMove = true;

        bool firstWillWin = false;
        for(int i = 3; i <= n; ++i) {
            firstWillWin = !oneMove || !twoMove;
            twoMove = oneMove;
            oneMove = firstWillWin;
        }
        return firstWillWin;
    }
};