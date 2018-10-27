class Solution {
private:
    void dfs(int n, std::vector<int>& indexResult, int& results) {
        if(indexResult.size() == n) {
            ++results;
            return;
        }

        for(int i = 0; i < n; ++i) {
            if(!isValid(i, indexResult)) continue;
            indexResult.push_back(i);
            dfs(n, indexResult, results);
            indexResult.pop_back();
        }
    }

    bool isValid(int index, const std::vector<int>& indexResult) {
        int len = indexResult.size();
        for(int i = 0; i < len; ++i) {
            if(index == indexResult[i] || len + index == i + indexResult[i] || len - index == i - indexResult[i]) return false;
        }
        return true;
    }

public:
    /**
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        int results = 0;
        std::vector<int> indexResult;
        dfs(n, indexResult, results);
        return results;
    }
};