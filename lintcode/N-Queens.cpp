class Solution {
private:
    void dfs(int n, std::vector<int>& indexResult, std::vector<vector<string> >& results) {
        if(indexResult.size() == n) {
            results.push_back(drawFromIndex(n, indexResult));
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
    
    std::vector<std::string> drawFromIndex(int n, const std::vector<int>& indexes) {
        std::vector<std::string> painting;
        for(auto index : indexes) {
            std::string line(n, '.');
            line[index] = 'Q';
            painting.push_back(line);
        }
        return painting;
    }
public:
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    vector<vector<string>> solveNQueens(int n) {
        std::vector<std::vector<std::string> > results;
        std::vector<int> indexResult;
        dfs(n, indexResult, results);
        return results;
    }
};