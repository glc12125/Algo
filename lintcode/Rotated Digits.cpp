class Solution {
public:
    /**
     * @param N: a positive number
     * @return: how many numbers X from 1 to N are good
     */
    int rotatedDigits(int N) {
        int result = 0;
        for(int i = 1; i < N+1; ++i) {
            int val = i;
            int count = 0;
            while(val > 0) {
                int v = val%10;
                if(v == 2 || v == 5 || v == 6 || v == 9){
                    ++count;
                } else if (v == 3 || v == 4 || v == 7) {
                    count = 0;
                    break;
                }
                val /= 10;
            }
            if(count > 0) ++result;
        }
        
        return result;
    }
};