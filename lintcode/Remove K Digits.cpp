class Solution {
public:
    /**
     * @param num: a string
     * @param k: an integer
     * @return: return a string
     */
    string removeKdigits(string &num, int k) {
        int len = num.size();
        if(k == len) return "0";
        string answer;

        for(int i = 0; i < len; ++i) {
            auto c = num[i];
            if(!answer.empty() && k > 0) {
                while(!answer.empty() && answer.back() > c) {
                    answer.pop_back();
                    if(--k == 0) break;
                }
            }
            answer.push_back(c);
        }
        while(k>0) {
            answer.pop_back();
            --k;
        }

        int startIndex = 0;
        while(answer[startIndex] == '0') ++startIndex;
        return answer.substr(startIndex);
    }
};