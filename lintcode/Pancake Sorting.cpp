// Time O(N^2), space O(1)
class Solution {
private:
    int getMaxIndex(const vector<int>& array, int size) {
        int maxIndex = 0;
        for(int i = 0; i < size; ++i) {
            if(array[i] > array[maxIndex]) {
                maxIndex = i;
            }
        }
        return maxIndex;
    }
public:
    /**
     * @param array: an integer array
     * @return: nothing
     */
    void pancakeSort(vector<int> &array) {
        for(int size = array.size(); size > 1; --size) {
            auto maxIndex = getMaxIndex(array, size);
            FlipTool::flip(array, maxIndex);
            FlipTool::flip(array, size - 1);
        }
    }
};