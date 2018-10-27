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

// Iterative approach
class Solution {
private:

    bool nextPermutation(std::string& str) {
        int firstDecreasingIndex = -1;
        int len = str.size();
        for(int i = len - 1; i > 0; --i) {
            if(str[i] > str[i-1]) {
                firstDecreasingIndex = i - 1;
                break;
            }
        }

        if(firstDecreasingIndex == -1) return false;

        for(int i = len - 1; i > firstDecreasingIndex; --i) {
            if(str[i] > str[firstDecreasingIndex]) {
                swap(str[i], str[firstDecreasingIndex]);
                break;
            }
        }
        reverseAllFromIndex(str, firstDecreasingIndex + 1, len - 1);
        return true;
    }

    void swap(char& a, char& b) {
        char temp = a;
        a = b;
        b = temp;
    }

    void reverseAllFromIndex(std::string& str, int index, int end) {
        for(int i = index, j = end; i < j; ++i, --j) {
            swap(str[i], str[j]);
        }
    }
public:


    vector<string> stringPermutation2(string &str) {
        std::vector<std::string> results;
        std::string permutation;
        std::sort(str.begin(), str.end());
        results.push_back(str);

        while(nextPermutation(str)) results.push_back(str);

        return results;
    }
};