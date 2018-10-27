class Solution {
private:
    std::vector<std::string> nextWords(const std::string& curr, const std::unordered_set<std::string>& dict) {
        std::vector<std::string> words;
        int len = curr.size();
        for(int i = 0; i < len; ++i) {
            for(char c = 'a'; c <= 'z'; ++c) {
                if(c == curr[i]) continue;
                std::string word = curr.substr(0, i) + c + curr.substr(i + 1);
                if(dict.count(word) > 0) words.push_back(word);
            }
        }

        return words;
    }

    void bfs(const std::string& start, const std::string& end, const unordered_set<string>& dict, std::unordered_map<std::string, int>& stepsFromDest, std::unordered_map<std::string, std::vector<std::string> >& neighbours) {

        std::queue<std::string> q;
        q.push(end);
        stepsFromDest[end] = 0;
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            int currentDistance = stepsFromDest[curr];
            auto words = nextWords(curr, dict);
            for(const auto& word : words) {
                neighbours[curr].push_back(word);
                if(stepsFromDest.count(word) > 0) continue;
                stepsFromDest[word] = currentDistance + 1;
                q.push(word);
            }
        }
    }

    void dfs(const std::string& end, const std::string& current, const unordered_set<string>& dict, const std::unordered_map<std::string, int>& stepsFromDest, const std::unordered_map<std::string, std::vector<std::string> >& neighbours, std::vector<std::string>& result, std::vector<std::vector<std::string> >& results) {
        if(current == end) {
            results.push_back(result);
            return;
        }

        auto words = neighbours.find(current)->second;
        auto currentDistance = stepsFromDest.find(current)->second;
        for(const auto& word : words) {
            if(stepsFromDest.count(word) == 0) continue;
            if(stepsFromDest.find(word)->second != currentDistance - 1) continue;
            result.push_back(word);
            dfs(end, word, dict, stepsFromDest, neighbours, result, results);
            result.pop_back();
        }
    }
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: a list of lists of string
     */
    vector<vector<string>> findLadders(string &start, string &end, unordered_set<string> &dict) {
        std::unordered_map<std::string, int> stepsFromDest;
        dict.insert(start);
        dict.insert(end);
        std::unordered_map<std::string, std::vector<std::string> > neighbours;
        bfs(start, end, dict, stepsFromDest, neighbours);

        std::vector<std::vector<std::string> > results;
        std::vector<std::string> result;
        result.push_back(start);
        dfs(end, start, dict, stepsFromDest, neighbours, result, results);
        return results;
    }
};