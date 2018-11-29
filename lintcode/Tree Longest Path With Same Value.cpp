class Solution {
private:
    struct ResultType {
        int m_leftMax;
        int m_rightMax;
        int m_max;
        ResultType() : m_leftMax(0), m_rightMax(0) , m_max(0) {}
        ResultType(int left, int right, int max) : m_leftMax(left), m_rightMax(right) , m_max(max) {}
    };

    ResultType divideAndConquer(const vector<int> &A, unordered_map<int, vector<int>>& tree, int node) {
        if(node - 1 == A.size()) return ResultType(0, 0, 0);

        ResultType leftResult;
        ResultType rightResult;
        int left = 0;
        int right = 0;
        if(tree.count(node)) {
            int subtreeSize = tree[node].size();
            if(subtreeSize > 0) {
                leftResult = divideAndConquer(A, tree, tree[node][0]);
                if(A[node-1] == A[tree[node][0]-1]) left = leftResult.m_leftMax + 1;
            }
            if(subtreeSize > 1) {
                rightResult = divideAndConquer(A, tree, tree[node][1]);
                if(A[node-1] == A[tree[node][1]-1]) right = rightResult.m_rightMax + 1;
            }
        }
        int len = left + 1 + right;

        len = std::max(len, std::max(leftResult.m_max, rightResult.m_max));
        //std::cout << "len of " << node << " is " << len << ", left: " << left << ", right: " << right << "\n";
        return ResultType(left, right, len);
    }
public:
    /**
     * @param A: as indicated in the description
     * @param E: as indicated in the description
     * @return: Return the number of edges on the longest path with same value.
     */
    int LongestPathWithSameValue(vector<int> &A, vector<int> &E) {

        unordered_map<int, vector<int>> tree;
        int lenE = E.size();
        int maxE = (lenE >> 1);
        for(int j = 0; j < maxE; ++j) {
            tree[E[j+j]].push_back(E[j+j+1]);
            tree[E[j+j+1]].push_back(E[j+j]);
        }

        /*for(auto edge : tree) {
            std::cout << "Edges of " << edge.first << ": ";
            for(auto e : edge.second) std::cout << e << " ";
            std::cout << "\n";
        }*/

        return divideAndConquer(A, tree, 1).m_max - 1;
    }
};

// DFS
class Solution {
public:
    /*
     * @param : as indicated in the description
     * @param : as indicated in the description
     * @return: Return the number of edges on the longest path with same value.
     */
    int LongestPathWithSameValue(vector<int> &A, vector<int> &E) {
        // write your code here
        int n = A.size();
        if (n == 0 || n == 1) {
            return 0;
        }
        edges = vector<unordered_set<int>>(1 + n);
        for (int j = 0; j < n - 1; ++j) {
            edges[E[2 * j]].insert(E[2 * j + 1]);
            edges[E[2 * j + 1]].insert(E[2 * j]);
        }

        maxLen = 0;
        dfs(A, 1, 0);
        return maxLen - 1;
    }

private:
    int maxLen;
    vector<unordered_set<int>> edges;
    int dfs(vector<int> &A, int start, int prev) {
        int currMax1 = 0, currMax2 = 0;
        for (int next : edges[start]) {
            if (next == prev) {
                continue;
            }
            int len = dfs(A, next, start);
            if (A[start - 1] == A[next - 1]) {
                if (len > currMax1) {
                    currMax2 = currMax1;
                    currMax1 = len;
                }
                else if (len > currMax2) {
                    currMax2 = len;
                }
            }
        }

        maxLen = max(maxLen, currMax1 + currMax2 + 1);
        return currMax1 + 1;
    }
};