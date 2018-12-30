class Solution {
public:
    /**
     * @param symb: the array of symbols
     * @param oper: the array of operators
     * @return: the number of ways
     */
    int countParenth(string &symb, string &oper) {
        int len = symb.size();
        int operLen = oper.size();
        if(len == 0 || operLen != len - 1) {
            return 0;
        }

        // T and F means symbols in range [i][j] counts for T and F
        vector<vector<int>> T(len, vector<int>(len));
        vector<vector<int>> F(len, vector<int>(len));
        for(int i = 0; i < len; ++i){
            if(symb[i] == 'T'){
                T[i][i] = 1;
            }else{
                F[i][i] = 1;
            }
        }

        for(int j = 0; j < len; ++j){
            for(int i = j-1; i >= 0; --i){
                T[i][j] = 0;
                F[i][j] = 0;
                for(int k = i; k < j; ++k){
                    switch(oper[k]) {
                        case '&':
                            T[i][j] += T[i][k] * T[k+1][j];
                            F[i][j] += (T[i][k] + F[i][k]) * (T[k+1][j] + F[k+1][j]) - T[i][k] * T[k+1][j];
                            break;
                        case '|':
                            T[i][j] += (T[i][k] + F[i][k]) * (T[k+1][j] + F[k+1][j]) - F[i][k] * F[k+1][j];
                            F[i][j] += F[i][k] * F[k+1][j];
                            break;
                        case '^':
                            T[i][j] += T[i][k] * F[k+1][j] + F[i][k] * T[k+1][j];
                            F[i][j] += T[i][k] * T[k+1][j] + F[i][k] * F[k+1][j];
                            break;
                    }
                }
            }
        }
        return T[0][len-1];
    }
};