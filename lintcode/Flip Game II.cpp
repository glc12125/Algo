// Time O(N^2)
class Solution {
private:
    bool dfs(string s, bool firstHand, unordered_map<string, bool>& mem) {
        if(mem.count(s)) {
            if(firstHand) return mem[s];
            else return !mem[s];
        }
        bool canWin = false;
        int len = s.size();
        for(int i = 0; i < len - 1; ++i) {
            if(s[i] != '+' || s[i+1] != '+') continue;
            s[i] = '-';
            s[i+1] = '-';
            if(!dfs(s, !firstHand, mem)) {
                canWin = true;
                break;
            }
            s[i] = '+';
            s[i+1] = '+';
        }
        if(firstHand) {
            mem[s] = canWin;
        }
        else {
            mem[s] = !canWin;
        }
        return canWin;
    }
public:
    /**
     * @param s: the given string
     * @return: if the starting player can guarantee a win
     */
    bool canWin(string &s) {
        unordered_map<string, bool> mem;
        return dfs(s, true, mem);
    }
};