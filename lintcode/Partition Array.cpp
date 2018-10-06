class Solution {
private:
    int partition(vector<int> & nums, int start, int end, int k) {
        if(start == end) return start;
        int i = start;
        int j = end;
        while(i <= j) {
            while(i <=j && nums[i] < k) {
                ++i;
            }
            while(i <= j && nums[j] >= k) {
                --j;
            }
            if(i <= j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                ++i;
                --j;
            }
        }
        //for(auto i : nums)
        //    std::cout << i << ", ";
        //std::cout << "\n";
        return i;
    }
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int k) {
        int size = nums.size();
        if(size == 0) return 0;
        return partition(nums, 0, size - 1, k);
    }
};