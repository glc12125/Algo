class Solution {
public:
    /**
     * @param strs: List[str]
     * @return: return an integer
     */
    int findLUSlength(vector<string> &strs) {
        sort(strs.begin(), strs.end(), [](const string &a, const string &b) {
           return a.size()>b.size();
        });
        for(int i=0; i<strs.size(); ++i) {
            int j=0;
            for(; j<strs.size(); ++j) {
                if(i!=j&&strs[i]==strs[j]) {
                    break;
                }
            }
            if(j==strs.size()) return strs[i].size();
        }
        return -1;
    }
};