// Time O(NlogN), space O(1)
class Solution {
public:
    /**
     * @param citations: a list of integers
     * @return: return a integer
     */
    int hIndex(vector<int> &citations) {
        int len = citations.size();
        if(len == 0) return 0;
        sort(citations.begin(), citations.end());
        if(citations[0] >= len) return len;
        int hIndex = -1;
        for(int i = len - 1; i >= 0; --i) {
            //len - citations[i] have no more than citations[i]
            // citations[i] have at least citations[i]
            if(citations[i] >= len - i ) { // len - i is supposed to be not greater than citations[i](H)
                hIndex = i;
            } else break;
        }
        return hIndex == -1 ? 0 : len - hIndex;
    }
};

//Time O(N), space O(N)
class Solution {
public:
    /**
     * @param citations: a list of integers
     * @return: return a integer
     */
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        vector<int> count(n + 1, 0);

        for(int i = 0; i < n; i++)
        {
            if(citations[i] >= n) {
                count[n]++;
            } else {
                count[citations[i]]++;
            };
        }

        if(count[n] >= n) {
            return n;
        }

        for(int i = n - 1; i >= 0; i--)
        {
            count[i] += count[i+1];
            if(count[i] >= i) {
                return i;
            }
        }

        return 0;
    }
};