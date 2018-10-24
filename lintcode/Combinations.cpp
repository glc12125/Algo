class Solution {
private:
    void dfs(int n, int current, int quota, std::vector<int>& list, std::vector<std::vector<int> >& results) {

        if(quota == 0) {
            results.push_back(list);
            return;
        }

        for(int i = current; i < n + 1; ++i) {
            list.push_back(i);
            dfs(n, i + 1, quota - 1, list, results);
            list.pop_back();
        }
    }
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int>> combine(int n, int k) {
        std::vector<std::vector<int> > results;
        if(n <= 0 || k <= 0) return results;
        std::vector<int> list;
        dfs(n, 1, k, list, results);
        return results;
    }
};