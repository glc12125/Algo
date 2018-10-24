class Solution {
private:
    void dfs(const std::vector<int> &candidates, int index, int target, std::vector<int>& answer, std::vector<std::vector<int> >& results){
        int len = candidates.size();
        if(target == 0) {
            results.push_back(answer);
            return;
        }
        if(target < candidates[index]) return;
        for(int i = index; i < len; ++i) {
            answer.push_back(candidates[i]);
            dfs(candidates, i, target - candidates[i], answer, results);
            answer.pop_back();
        }
    }
public:
    /**
     * @param candidates: A list of integers
     * @param target: An integer
     * @return: A list of lists of integers
     */
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        std::vector<std::vector<int> > results;
        if(candidates.size() == 0) return results;
        std::set<int> uniqueNums(candidates.begin(), candidates.end());
        std::vector<int> uniqueCandidates;
        std::copy(uniqueNums.begin(), uniqueNums.end(), std::back_inserter(uniqueCandidates));
        std::vector<int> answer;
        dfs(uniqueCandidates, 0, target, answer, results);
        return results;
    }
};