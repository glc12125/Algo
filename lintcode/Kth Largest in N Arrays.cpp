class Solution {
public:
    /**
     * @param arrays: a list of array
     * @param k: An integer
     * @return: an integer, K-th largest element in N arrays
     */
    int KthInArrays(vector<vector<int>> &arrays, int k) {
        int len = arrays.size();
        if(len == 0) return 0;

        priority_queue<int, vector<int>, std::greater<int>> q;

        for(int i = 0; i < len; ++i) {
            int arrayLen = arrays[i].size();
            for(int j = 0; j < arrayLen; ++j) {
                q.push(arrays[i][j]);
                if(q.size() > k) q.pop();
            }
        }

        return q.top();
    }
};