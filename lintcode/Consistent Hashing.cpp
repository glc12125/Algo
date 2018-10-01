class Solution {
public:
    /*
     * @param n: a positive integer
     * @return: n x 3 matrix
     */
    vector<vector<int>> consistentHashing(int n) {
        std::vector<vector<int> > result;
        std::vector<int> entry = {0, 359, 1};
        result.push_back(entry);
        for(int i = 1; i < n; ++i) {
            int targetIndex = 0;
            for(int j = 1; j < i; ++j) {
                if(result[j][1] - result[j][0] > result[targetIndex][1] - result[targetIndex][0]) {
                    targetIndex = j;
                }
            }
            int start = result[targetIndex][0];
            int end = result[targetIndex][1];
            result[targetIndex][1] = (start + end) / 2;
            entry[0] = (start + end) / 2 + 1;
            entry[1] = end;
            entry[2] = i + 1;
            result.push_back(entry);
        }
        return result;
    }
};