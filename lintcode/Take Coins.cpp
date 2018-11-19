// Prefix Sum, time O(N), space O(N)
class Solution {
public:
    /**
     * @param list: The coins
     * @param k: The k
     * @return: The answer
     */
    int takeCoins(vector<int> &list, int k) {
        if(k == 0) return 0;
        int len = list.size();
        if(k >= len) return accumulate(list.begin(), list.end(), 0);

        vector<long> preSum(len + 1, 0);
        for(int i = 1; i <= len; ++i) {
            preSum[i] = preSum[i-1] + list[i-1];
        }

        long sum = 0;
        for(int i = 0; i <= k; ++i) {
            int l = i; // Previous l elements sum
            int r = len - (k - i); // right part has k - i elements, so the sum of the right part is preSum[len] - preSum[r]
            sum = std::max(sum, preSum[len] - preSum[r] + preSum[l]);
        }
        return sum;
    }
};

// Two pointers, time O(K), space O(1)
class Solution {
public:
    /**
     * @param list: The coins
     * @param k: The k
     * @return: The answer
     */
    int takeCoins(vector<int> &list, int k) {
        if(k == 0) return 0;
        int len = list.size();
        if(k >= len) return accumulate(list.begin(), list.end(), 0);

        int l = 0;
        int r = len - 1;
        int sum = 0;
        while(l < k) {
            sum += list[l++];
        }
        int maxSum = sum;
        --l;
        while(k-- > 0) {
            sum -= list[l--];
            sum += list[r--];
            maxSum = std::max(maxSum, sum);
        }
        return maxSum;
    }
};