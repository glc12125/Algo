class Solution {
public:
    /**
     * @param A: lists A
     * @param B: lists B
     * @return: the index mapping
     */
    vector<int> anagramMappings(vector<int> &A, vector<int> &B) {
        int size = A.size();
        if(size == 0) return {};
        std::unordered_map<int,int> m;
        for(int i = 0; i < size; ++i) m[B[i]] = i;
        std::vector<int> result(size, 0);
        for(int i = 0; i < size; ++i) result[i] = m[A[i]];
        return result;
    }
};