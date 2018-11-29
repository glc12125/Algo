class Solution {
private:
    int select(int n, std::vector<int>& nums, int start, int end) {
        if(start >= end) return nums[n];
        int i = start;
        int j = end;
        int pivot = nums[(i+j)/2];
        while(i <= j) {
            while(i <= j && nums[i] > pivot) ++i;
            while(i <= j && nums[j] < pivot) --j;
            if(i<=j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                ++i;
                --j;
            }
        }

        if(n <= j) return select(n, nums, start, j);
        if(n >= i) return select(n, nums, i, end);
        return nums[n];
    }
public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int> &nums) {
        int len = nums.size();
        if(len == 0) return;

        int mid = select(len >> 1, nums, 0, len - 1);

        vector<int> ans(len);
        for (int i = 0; i < len; i++) {
            ans[i] = mid;
        }
        int l, r;
        if (len % 2 == 0) {
            l = len - 2;
            r = 1;
            for (int i = 0; i < len; i++) {
                if (nums[i] < mid) {
                    ans[l] = nums[i];
                    l -= 2;
                } else if (nums[i] > mid) {
                    ans[r] = nums[i];
                    r += 2;
                }
            }
        } else {
            l = 0;
            r = len - 2;
            for (int i = 0; i < len; i++) {
                if (nums[i] < mid) {
                    ans[l] = nums[i];
                    l += 2;
                } else if (nums[i] > mid) {
                    ans[r] = nums[i];
                    r -= 2;
                }
            }
        }
        for (int i = 0; i < len; i++) {
            nums[i] = ans[i];
        }
    }
};