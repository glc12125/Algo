class Solution {
private:
    void dfs(int target, int current, std::vector<int>& answer, std::vector<std::vector<int> >& results) {
        if(answer.size() > 0) {
            answer.push_back(target);
            results.push_back(answer);
            answer.pop_back();
        }

        for(int i = current; i <= target; ++i) {
            if(target / i < i) break;
            if(target % i == 0) {
                answer.push_back(i);
                dfs(target / i, i, answer, results);
                answer.pop_back();
            }
        }
    }
public:
    /**
     * @param n: An integer
     * @return: a list of combination
     */
    vector<vector<int>> getFactors(int n) {
        std::vector<std::vector<int> > results;
        std::vector<int> answer;
        dfs(n, 2, answer, results);
        return results;
    }
};