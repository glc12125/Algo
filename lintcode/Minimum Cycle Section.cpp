class Solution {
public:
    /**
     * @param array: an integer array
     * @return: the length of the minimum cycle section
     */
    int minimumCycleSection(vector<int> &array) {
        if( array.size() <= 1) return array.size();
        int next[array.size()]={0};
        int i = 1;
        int len = 0;
        while( i < array.size()){
            if(array[i] == array[len]){
                next[i++] = ++len;
            }else{
                if(len != 0) {
                    len = next[len-1];
                } else {
                    next[i++] = 0;
                }
            }
        }

        return i - next[i-1];
    }
};