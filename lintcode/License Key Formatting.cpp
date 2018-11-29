class Solution {
public:
    /**
     * @param S: a string
     * @param K: a integer
     * @return: return a string
     */
    string licenseKeyFormatting(string &S, int K) {
        // write your code here
        int charCount = 0;
        for(auto c : S){
            if(c != '-') ++charCount;
        }

        int mod = charCount % K;
        int total = S.size();
        int dashCount = mod ? charCount / K : charCount / K - 1;
        int resultLen = charCount + dashCount;
        std::string result(resultLen, '-');

        int i = 0;
        int j = 0;
        for(; j < mod; ++i){
            if(S[i] != '-') {
                result[j] = toupper(S[i]);
                ++j;
            }
        }
        if(mod) ++j;
        int k = 0;
        for(; i < total; ++i) {
            if(S[i] != '-')  {
                result[j] = toupper(S[i]);
                ++j;
                if((++k) % K == 0) ++j;
            }
        }
        return result;
    }
};