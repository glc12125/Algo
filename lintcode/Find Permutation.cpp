class Solution {
private:
    void reverse(vector<int>& result, int l, int r) {
        while(l < r) {
            swap(result[l++], result[r--]);
        }
    }
public:
    /**
     * @param s: a string
     * @return: return a list of integers
     */
    vector<int> findPermutation(string &s) {
        int len = s.size();
        if(len == 0) return {1};
        int resultLen = len + 1;
        vector<int> result(resultLen);
        for(int i = 0; i < resultLen; ++i) {
            result[i] = i + 1;
        }

        for(int i = 0; i < len; ++i) {
            if(s[i] == 'D') {
                int r = i;
                while(r < len && s[r] == 'D') ++r;
                reverse(result, i, r);
                i = r;
            }
        }
        return result;
    }
};