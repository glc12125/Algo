class Solution {
private:
    void dfs(const string& num, int index, int target, const string& candidate, long long last, vector<string>& answer) {
        int len = num.size();
        if(index == len) {
            if(target == 0) {
                answer.emplace_back(candidate);
            }
            return;
        }

        long long x = 0;
        string xStr;
        for(int i = index; i < len; ++i) {
            x = x * 10 + num[i] - '0';
            xStr += num[i];
            if(index == 0) {
                dfs(num, i + 1, target - x, candidate + xStr, x, answer);
            } else {
                dfs(num, i + 1, target + last - last * x, candidate + "*" + xStr, last * x, answer);
                dfs(num, i + 1, target - x, candidate + "+" + xStr, x, answer);
                dfs(num, i + 1, target + x, candidate + "-" + xStr, -x, answer);
            }
            if(x == 0) {break;}
        }
    }
public:
    /**
     * @param num: a string contains only digits 0-9
     * @param target: An integer
     * @return: return all possibilities
     */
    vector<string> addOperators(string &num, int target) {
        vector<string> answer;
        dfs(num, 0, target, "", 0, answer);
        return answer;
    }
};
