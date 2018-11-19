class Solution {
public:
    /**
     * @param numerator: a integer
     * @param denominator: a integer
     * @return: return a string
     */
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator == 0) return "";
        vector<char> res;
        int whole = numerator / denominator;
        numerator %= denominator;
        if (numerator == 0) return to_string(whole);

        unordered_map<int,int> pos;
        while (numerator!=0) {
            if (pos.count(numerator)) {
                string norep = string(res.begin(), res.begin()+pos[numerator]);
                string rep = string(res.begin()+pos[numerator], res.end());
                return to_string(whole) + "." + norep +"(" + rep+")";
            }
            pos[numerator] = res.size();
            numerator *= 10;
            int q = numerator / denominator;
            numerator %= denominator;
            res.emplace_back('0'+q);
            if (numerator == 0) {
                return to_string(whole)+"." + string(res.begin(), res.end());
            }
        }
        return "";
    }
};