class Solution {
private:
    void dfs(const std::string& str, std::vector<bool>& visited, std::string& permutation, std::vector<std::string>& results) {
        if(permutation.size() == str.size()) {
            results.push_back(permutation);
        }

        int len = str.size();
        for(int i = 0; i < len; ++i) {
            if(visited[i]) continue;
            if(i > 0 && str[i] == str[i-1] && !visited[i-1]) continue;

            permutation += str[i];
            visited[i] = true;
            dfs(str, visited, permutation, results);
            visited[i] = false;
            permutation.pop_back();
        }
    }
public:
    /**
     * @param str: A string
     * @return: all permutations
     */
    vector<string> stringPermutation2(string &str) {
        std::vector<std::string> results;
        std::string permutation;
        std::vector<bool> visited(str.size(), false);

        std::sort(str.begin(), str.end());
        dfs(str, visited, permutation, results);
        return results;
    }
};