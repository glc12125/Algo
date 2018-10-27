class Solution {
private:
    void dfs(const std::vector<int>& nums, std::vector<bool>& visited, std::vector<int>& answer, std::vector<std::vector<int> >& results) {
        int len = nums.size();
        if(answer.size() == len) {
            results.push_back(answer);
            return;
        }

        for(int i = 0; i < len; ++i) {
            if(visited[i]) continue;
            if(i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;
            answer.push_back(nums[i]);
            visited[i] = true;
            dfs(nums, visited, answer, results);
            visited[i] = false;
            answer.pop_back();
        }
    }
public:
    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        std::vector<std::vector<int> > results;
        std::vector<int> answer;
        std::vector<bool> visited(nums.size(), false);
        std::sort(nums.begin(), nums.end());
        dfs(nums, visited, answer, results);
        return results;
    }
};