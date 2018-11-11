class Solution {
public:
    /*
     * @param A: An integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int> &A) {
        int len = A.size();
        if(len == 0) return {};

        vector<long> prefixSum(len + 1, 0);
        for(int i = 1; i <= len; ++i) {
            prefixSum[i] = prefixSum[i-1] + A[i-1];
        }


        long minSumIndex = 0;
        long maxSubArraySum = INT_MIN;
        vector<int> result(2);
        for(int i = 1; i <= len; ++i) {
            if(prefixSum[i] < prefixSum[minSumIndex]) {
                minSumIndex = i;
            }
            if(maxSubArraySum < prefixSum[i] - prefixSum[minSumIndex]) {
                maxSubArraySum = prefixSum[i] - prefixSum[minSumIndex];
                result[0] = minSumIndex;
                result[1] = i - 1;
            }
        }

        return result;
    }
};