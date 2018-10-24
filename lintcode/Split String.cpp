class Solution {
private:
    void dfs(const std::string& s, int index, std::vector<std::string>& splits, std::vector<std::vector<std::string> >& results) {
        int len = s.size();
        if(index >= len) {
            results.push_back(splits);
            return;
        }

        splits.push_back(s.substr(index, 1));
        dfs(s, index + 1, splits, results);
        splits.pop_back();
        if(index < len - 1) {
            splits.push_back(s.substr(index, 2));
            dfs(s, index + 2, splits, results);
            splits.pop_back();
        }
    }
public:
    /*
     * @param : a string to be split
     * @return: all possible split string array
     */
    vector<vector<string>> splitString(string& s) {
        std::vector<std::vector<std::string> > results;
        std::vector<std::string> splits;
        dfs(s, 0, splits, results);
        return results;
    }
};

// Combination based approach
class Solution {
private:
    void dfs(const std::string& s, int index, std::vector<std::string>& splits, std::vector<std::vector<std::string> >& results) {
        int len = s.size();
        if(index >= len) {
            results.push_back(splits);
            return;
        }

        for(int i = 1; i < 3; ++i) {
            if(index + i <= len) {
                splits.push_back(s.substr(index, i));
                dfs(s, index + i, splits, results);
                splits.pop_back();
            }
        }
    }
public:
    /*
     * @param : a string to be split
     * @return: all possible split string array
     */
    vector<vector<string>> splitString(string& s) {
        std::vector<std::vector<std::string> > results;
        std::vector<std::string> splits;
        dfs(s, 0, splits, results);
        return results;
    }
};