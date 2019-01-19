// Time O(N), space O(N)
class Solution {
private:
    void dfsCalculateSubNodes(vector<vector<int>>& neighbour, int node, int prevNode, vector<int>& subNodes, vector<int>& result) {
        subNodes[node] = 1;

        for(auto& next : neighbour[node]) {
            if(next == prevNode) {continue;}
            // first calculate all subnodes
            dfsCalculateSubNodes(neighbour, next, node, subNodes, result);
            subNodes[node] += subNodes[next];
            result[node] += result[next] + subNodes[next];
        }
    }

    void dfsPopulate(vector<vector<int>>& neighbour, int n, int node, int prevNode, vector<int>& subNodes, vector<int>& result) {
        for(auto& next : neighbour[node]) {
            if(next == prevNode) {continue;}
            /* From top to bottom, subNodes records how many sub
            * nodes does node have. So each time we go from node
            * to its subnode, we add n - subnodes[node] (further
            * from original root) and  substract subnodes[node] (
            * closer to the leaf)
            */
            result[next] = result[node] - subNodes[next] + n - subNodes[next];
            dfsPopulate(neighbour, n, next, node, subNodes, result);
        }
    }
public:
    /**
     * @param N: an integer
     * @param edges: the edges
     * @return: a list ans, where ans[i] is the sum of the distances between node i and all other nodes
     */
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges) {
        int edgeLen = edges.size();
        if(edgeLen != N - 1) return {};

        vector<vector<int>> neighbour(N);
        for(const auto& edge : edges) {
            neighbour[edge[0]].push_back(edge[1]);
            neighbour[edge[1]].push_back(edge[0]);
        }

        vector<int> answer(N, 0);
        vector<int> subNodes(N, 0);

        dfsCalculateSubNodes(neighbour, 0, -1, subNodes, answer);
        dfsPopulate(neighbour, N, 0, -1, subNodes, answer);

        return answer;
    }
};