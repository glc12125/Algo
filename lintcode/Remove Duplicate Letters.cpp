class Solution {
public:
    /**
     * @param s: a string
     * @return: return a string
     */
    string removeDuplicateLetters(string &s) {
        int hash[256] = {0};
        int visited[256] = {0};
        std::string result = "0";

        for (auto c : s) ++hash[c];
        for(auto c : s) {
            --hash[c];
            if(visited[c]) continue;
            while(c < result.back() && hash[result.back()]) {
                visited[result.back()] = 0;
                result.pop_back();
            }

            result += c;
            visited[c] = 1;
        }

        return result.substr(1);
    }
};