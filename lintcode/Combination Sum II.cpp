class Solution {
private:
    void dfs(const std::vector<int> &num, int index, int target, std::vector<int>& answer, std::vector<std::vector<int> >& results){
        int len = num.size();
        if(target == 0) {
            results.push_back(answer);
            return;
        }
        if(target < num[index]) return;
        for(int i = index; i < len; ++i) {
            if(i > 0 && num[i] == num[i-1] && i > index) continue;
            answer.push_back(num[i]);
            dfs(num, i + 1, target - num[i], answer, results);
            answer.pop_back();
        }
    }
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        std::vector<std::vector<int> > results;
        if(num.size() == 0) return results;
        std::sort(num.begin(), num.end());
        std::vector<int> answer;
        dfs(num, 0, target, answer, results);
        return results;
    }
};