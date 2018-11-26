// BFS
class Solution {
public:
    /**
     * @param graph: a 2D integers array
     * @return: return a list of integers
     */
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        //graph.push_back({});
        int len = graph.size();
        if(len == 0) return {};
        unordered_map<int, unordered_set<int>> neighbours;
        unordered_map<int, int> outDegrees;
        for(int i = 0; i < len; ++i) {
            outDegrees[i] = graph[i].size();
            for(auto goingTo : graph[i]) {
                neighbours[goingTo].insert(i);
            }
        }

        queue<int> q;
        unordered_set<int> visited;
        for(auto i : outDegrees) {
            if(i.second == 0) {
                q.push(i.first);
                visited.insert(i.first);
            }
        }

        vector<int> result;
        while(!q.empty()) {
            auto curr = q.front();
            result.push_back(curr);
            q.pop();
            for(auto neighbour : neighbours[curr]) {
                if(--outDegrees[neighbour] == 0) {
                    if(visited.count(neighbour)) continue;
                    visited.insert(neighbour);
                    q.push(neighbour);
                }
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};

// DFS
class Solution {
private:
    bool dfs(const vector<vector<int>> &graph, int i, unordered_set<int>& safe, unordered_set<int>& visited) {

        if(safe.count(i)) {return true;}
        const auto& goingTos = graph[i];
        if(goingTos.empty()) {
            safe.insert(i);
            return true;
        }
        if(visited.count(i)) {
            return false;
        }

        visited.insert(i);
        for(auto goingTo : goingTos) {
            //if(safe.count(goingTo)) {continue;}
            if(!dfs(graph, goingTo, safe, visited)) {
                return false;
            }
        }
        safe.insert(i);
        return true;
    }
public:
    /**
     * @param graph: a 2D integers array
     * @return: return a list of integers
     */
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        //graph.push_back({});
        int len = graph.size();
        if(len == 0) return {};
        unordered_set<int> safe;
        unordered_set<int> visited;
        vector<int> result;
        for(int i = 0; i < len; ++i) {
            if(dfs(graph, i, safe, visited)) {
                result.push_back(i);
            }
        }
        return result;
    }
};