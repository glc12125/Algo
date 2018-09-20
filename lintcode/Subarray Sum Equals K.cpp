// The key is to avoid duplicated calculation. Create a hash table to store
// the count of sums. After creating this hash table, check if there is any
// thing like sum1 - sum2 = k, this means the sum of elements between the
// ending point of sum1 and sum2 is k. And all of this can be done in a single
// loop
class Solution {
public:
    /**
     * @param nums: a list of integer
     * @param k: an integer
     * @return: return an integer, denote the number of continuous subarrays whose sum equals to k
     */
    int subarraySumEqualsK(vector<int> &nums, int k) {
        int size = nums.size();
        int result = 0;
        int sum = 0;
        std::unordered_map<int, int> m = {{0,1}};
        for(int i = 0; i < size; ++i) {
            sum += nums[i];
            if(m.count(sum-k) > 0) result += m[sum-k];
            ++m[sum];
        }
        return result;
    }
};