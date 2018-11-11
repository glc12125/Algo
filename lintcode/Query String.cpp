class Solution {
public:
    /**
     * @param str: the string
     * @param n: the n
     * @return: yes or no
     */
    string queryString(string &str, int n) {
        vector<bool> m(n+1, false);

        int len = str.size();
        for(int i = 0; i < len; i++)
        {
            int val = 0;
            for(int j = i; j < len; ++j) {
                val <<= 1;
                val += (str[j]-'0');
                if(val <= n) m[val] = true;
                else break;
            }
        }

        for(int i = 0; i <= n; i ++)
        {
            if(!m[i]) return "no";
        }
        return "yes";
    }

};