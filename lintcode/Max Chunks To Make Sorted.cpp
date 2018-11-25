/*
每个数应该在的位置就是它本身的值，从第一个数开始，每次更新farest position，
index走到farest的时候就分成一块，比如 10 234 ， 1的farest=1, index继续走
到1时值为0，0的位置在0，＜ 1，所以farest不能更新，index = farest，从这里断开
count ++, 每次index == farest的时候就count++
*/
class Solution {
public:
    /**
     * @param arr: a permutation of N
     * @return: the most number of chunks
     */
    int maxChunksToSorted(vector<int> &arr) {
        int len = arr.size();
        if(len == 0) return 0;
        int cnt = 0;
        int i = 0;
        int farest = arr[0];
        while(i < len)
        {
            while(i <= farest)
            {
                farest = max(farest, arr[i]);
                ++i;
            }
            ++cnt;
            farest = arr[i];
        }
        return cnt;
    }
};