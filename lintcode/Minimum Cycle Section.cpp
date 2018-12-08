class Solution {
public:
    /**
     * @param array: an integer array
     * @return: the length of the minimum cycle section
     */
    int minimumCycleSection(vector<int> &array) {
        if( array.size() <= 1) return array.size();
        int next[array.size()+1]={0};
        next[0] = -1;
        int i = 0,j = -1;
        while( i < array.size()){
            if( j < 0 || array[i] == array[j]){
                next[++i] = ++j;
            }else{
                j = next[j];
            }
        }
        return i - next[i];
    }
};