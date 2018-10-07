class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        int size = S.size();
        std::sort(S.begin(), S.end());
        int result = 0;
        for(int i = size - 1; i > 1; --i) {
            int c = S[i];
            int start = 0;
            int end = i - 1;
            while(start < end) {
                if(S[start] + S[end] > c) {
                    result += (end - start);
                    --end;
                } else {++start;}
            }
        }
        return result;
    }
};