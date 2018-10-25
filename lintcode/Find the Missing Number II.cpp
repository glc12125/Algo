class Solution {
private:
    int m_missing;
    void dfs(int n, const std::string& str, int index, std::unordered_set<int>& collected, int sum) {
        int len = str.size();
        if(index >= len) {
            if(collected.size() == n - 1) {
                m_missing = sum;
            }
            return;
        }
        
        if(str[index] == '0') return;
        for(int i = index; i < len; ++i) {
            int candidate = std::stoi(str.substr(index, i - index + 1));
            if(candidate <= n && collected.count(candidate) == 0) {
                collected.insert(candidate);
                dfs(n, str, i + 1, collected, sum - candidate);
                collected.erase(candidate);
            } else if (candidate > n) {
                break;
            }
        }
    }
public:
    /**
     * @param n: An integer
     * @param str: a string with number from 1-n in random order and miss one number
     * @return: An integer
     */
    int findMissing2(int n, string &str) {
        std::unordered_set<int> collected;
        int sum = n * (n + 1) / 2;
        dfs(n, str, 0, collected, sum);
        return m_missing;
    }
};