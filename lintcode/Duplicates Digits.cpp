class Solution {
public:
    /**
     * @param n: The integer n.
     * @return: The number of of numbers that have duplicates digits.
     */
    long long countNumbers(long long n) {
        long long limit=pow(10, 10);
        string str=to_string(n);
        int len=str.size();
        if(len>10) return n-countUniqueWithLen(len);

        long long unique=countUniqueWithLen(len-1); // count the unique choices of "xxx" in "dxxx", without the first
        //cout<<"unique="<<unique<<endl;

        // count unique in fixed digit numbers "dxxx"
        vector<int> used(10, false);
        int start=0;
        unique+=(str[start]-'0'-1)*countUniqueWithFirst(len, 10-start-1); // for "(d-1)xxx"
        used[str[start]-'0']=true;
        //cout<<"start="<<start<<", unique="<<unique<<endl;


        while(++start<len) {
            int d=str[start]-'0', cnt=d;
            for(int i=0; i<d; ++i) {
                if(used[i]) --cnt;
            }

            unique+=cnt*countUniqueWithFirst(len-start, 10-start-1);
            //cout<<"in while: d="<<d<<", cnt="<<cnt<<", unique="<<unique<<endl;
            if(used[d]) return n-unique;
            used[d]=true;
        }
        unique+=1; // unique self
        return n-unique;
    }
    long long countUniqueWithLen(int len) {
        int res=9, unique=9, choice=9;
        while(len>1&&choice>0) {
            unique*=choice;
            res+=unique;
            --len;
            --choice;
        }
        return res;
    }
    long long countUniqueWithFirst(int n, int choice) {
        int unique=1;
        while(n>1&&choice>0) { //9*8
            unique*=choice;
            --choice;
            --n;
        }
        //cout<<"n="<<n<<", choice="<<choice<<", unique="<<unique<<endl;
        return unique;
    }
};