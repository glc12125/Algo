class Solution {
private:
    // Keep decreasing order
    int getFirstGT(const vector<int>& array, int target) {
        if(array.size() == 0) return 0;

        int start = 0;
        int end = array.size() - 1;
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if(array[mid] > target) end = mid;
            else start = mid;
        }

        if(array[start] > target) return start;
        if(array[end] > target) return end;

        return array.size();
    }
public:
    /**
     * @param arrayIn: The original array.
     * @return: Count the minimum number of subarrays.
     */
    int LeastSubsequences(vector<int> &arrayIn) {
        int count = 0;
        vector<int> decreasingContainer;
        for(auto num : arrayIn) {
            int pos = getFirstGT(decreasingContainer, num);
            if(pos == decreasingContainer.size()) {
                ++count;
                decreasingContainer.push_back(num);
            } else decreasingContainer[pos] = num;
        }
        return count;
    }
};