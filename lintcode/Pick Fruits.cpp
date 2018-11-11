class Solution {
private:
    int pick(const vector<int>& arr, int start) {
        unordered_set<int> chosenfruitType;
        int size = arr.size();
        int cnt = 0;
        for(int i = start; i < size; ++i) {
            if(chosenfruitType.size() < 2) {
                ++cnt;
                chosenfruitType.insert(arr[i]);
            } else {
                if(chosenfruitType.count(arr[i])) ++cnt;
                else return cnt;
            }
        }
        return cnt;
    }
public:
    /**
     * @param arr: the arr
     * @return: the length of the longset subarray
     */
    int pickFruits(vector<int> &arr) {
        int maxCnt = 0;
        int size = arr.size();
        int slow = 0;
        int fast = 0;
        unordered_map<int, int> typeCounts;
        while(fast < size) {
            if(typeCounts.size() < 2) {
                ++typeCounts[arr[fast++]];
            } else {
                if(typeCounts.count(arr[fast])) {
                    ++typeCounts[arr[fast]];
                    ++fast;
                } else {
                    if(--typeCounts[arr[slow]] == 0) typeCounts.erase(arr[slow]);
                    ++slow;
                }
            }
            maxCnt = std::max(maxCnt, fast - slow);
        }
        return maxCnt;
    }
};