class Solution {
private:
    void dp(vector<int> &a, int startIndex, std::unordered_set<int> chosen, int& count) {
        if(chosen.size() > 2) {
            --count;
            return;
        }
        if(startIndex > a.size() - 1) return;

        if(chosen.size() == 0) {
            int currentCount = count;
            dp(a, startIndex + 1, chosen, currentCount);
            chosen.insert(a[startIndex]);
            int increasedCount = count + 1;
            dp(a, startIndex + 1, chosen, increasedCount);
            count = std::max(currentCount, increasedCount);
        } else {
            chosen.insert(a[startIndex]);
            ++count;
            dp(a, startIndex + 1, chosen, count);
        }
    }
public:
    /**
     * @param a: the array a
     * @return: return the maximum length
     */
    int maxLenDFS(vector<int> &a) {
        int len = a.size();
        if(len < 3) return len;
        std::unordered_set<int> chosen;
        int count = 0;
        dp(a, 0, chosen, count);
        return count;
    }

    int maxLen(vector<int>& arr) {
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