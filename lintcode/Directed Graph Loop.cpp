class Solution {
public:
    /**
     * @param start: The start points set
     * @param end: The end points set
     * @return: Return if the graph is cyclic
     */
    bool isCyclicGraph(vector<int> &start, vector<int> &end) {
        int edgeNum = start.size();
        if(edgeNum == 0) return false;

        unordered_map<int, unordered_set<int>> neighbours;
        unordered_map<int, int> indegrees;
        for(int i = 0; i < edgeNum; ++i) {
            if(neighbours.count(end[i]) == 0) neighbours[end[i]]; // create node with indegree 0;
            neighbours[start[i]].insert(end[i]);
            indegrees[end[i]]++;
        }

        int vertexNum = neighbours.size();
        int connectedNum = 0;
        queue<int> q;
        unordered_set<int> visited;
        for(auto i : neighbours) {
            if(indegrees.count(i.first) == 0) {
                q.push(i.first);
                visited.insert(i.first);
            }
        }


        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            ++connectedNum;
            for(auto neighbour : neighbours[curr]) {
                if(visited.count(neighbour)) continue;
                if(--indegrees[neighbour] == 0) {
                    q.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }

        return connectedNum != vertexNum;
    }
};