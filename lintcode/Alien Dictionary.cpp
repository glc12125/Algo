class Solution {
private:
    unordered_map<char, unordered_set<char>> buildGraph(const vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;

        // Create nodes
        for(const auto& word: words) {
            for(auto c : word) {
                graph[c];
            }
        }

        // Create edges
        int wordNum = words.size() - 1;
        for(int i = 0; i < wordNum; ++i) {
            int currWordLen = words[i].size();
            int nextWordLen = words[i+1].size();
            for(int j = 0; j < currWordLen && j < nextWordLen; ++j) {
                if(words[i][j] != words[i+1][j]) {
                    // the character goes above the next line in the same
                    // position must apear before in given dictionary
                    graph[words[i][j]].insert(words[i+1][j]);
                    break;
                }
            }
        }
        return graph;
    }

    unordered_map<char, int> getInDegrees(const unordered_map<char, unordered_set<char>>& graph) {
        unordered_map<char, int> inDegrees;

        for(auto it : graph) {
            if(inDegrees.count(it.first) == 0) {
                inDegrees[it.first] = 0;
            }
            for(auto c : it.second) {
                ++inDegrees[c];
            }
        }
        return inDegrees;
    }
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string alienOrder(vector<string> &words) {
        auto graph = buildGraph(words);
        auto indegrees = getInDegrees(graph);

        priority_queue<char, vector<char>, std::greater<char>> q;
        for(auto it : indegrees) {
            if(it.second == 0) {
                q.push(it.first);
            }
        }

        string result;
        while(!q.empty()) {
            auto c = q.top();
            q.pop();
            result += c;
            for(auto next : graph[c]) {
                if(--indegrees[next] == 0) {
                    q.push(next);
                }
            }
        }

        return result.size() == graph.size() ? result : "";
    }
};