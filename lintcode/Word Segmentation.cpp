class Solution {
private:
    void dfs(const string&s, int index, int k, vector<string>& candidate) {
        if(index >= s.size()) {
            if(candidate.size() < m_minCount) {
                m_minCount = candidate.size();
                m_answer = candidate;
            }
            return;
        }
        
        if((index + k < s.size() && s.at(index + k) == ' ') || index + k == s.size()) {
            candidate.push_back(s.substr(index, k));
            dfs(s, index + k + 1, k, candidate);
        } else if (index + k > s.size()) {
            int len = s.size() - index;
            candidate.push_back(s.substr(index, len));
            dfs(s, index + len, k, candidate);
        }
        else {
            int i = std::min(index + k, (int)s.size() - 1);
            while(s.at(i--) != ' ');
            candidate.push_back(s.substr(index, i + 1 - index));
            dfs(s, i + 2, k, candidate);
        }

    }
    
    int m_minCount = INT_MAX;
    std::vector<string> m_answer;
public:
    /**
     * @param s: the string
     * @param k: the k
     * @return: the answer
     */
    vector<string> wordSegmentation(string &s, int k) {
        std::vector<string> candidate;
        dfs(s, 0, k, candidate);
        return m_answer;
    }
};