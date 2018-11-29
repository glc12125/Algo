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