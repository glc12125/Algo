class Solution {
private:
    void dfs(string number, int n, vector<string>& result) {
        if(n == number.size()) {
            result.push_back(number);
            return;
        }

        if(number.size() + 2 < n) {
            dfs('0' + number + '0', n, result);
        }
        dfs('1' + number + '1', n, result);
        dfs('6' + number + '9', n, result);
        dfs('8' + number + '8', n, result);
        dfs('9' + number + '6', n, result);
    }
public:
    /**
     * @param n: the length of strobogrammatic number
     * @return: All strobogrammatic numbers
     */
    vector<string> findStrobogrammatic(int n) {
        if(n == 0) return {""};

        vector<string> result;
        if(n%2) {
            dfs("0", n, result);
            dfs("1", n, result);
            dfs("8", n, result);
        } else {
            dfs("", n, result);
        }

        return result;
    }
};