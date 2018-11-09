// Time O(NlogN)
class Solution {
private:
    int getSTE(const vector<int>& nums, int mid) {
        int cnt = 0;
        for(auto num : nums) {
            if(num <= mid) ++cnt;
        }
        return cnt;
    }
public:
    /**
     * @param nums: an array containing n + 1 integers which is between 1 and n
     * @return: the duplicate one
     */
    int findDuplicate(vector<int> &nums) {
        int len = nums.size();
        int l = 0;
        int r = len - 1;
        while(l + 1 < r) {
            int mid = l + (r - l) / 2;
            if(getSTE(nums, mid) <= mid) {
                l = mid;
            } else r = mid;
        }

        if(getSTE(nums, l) <= l) return r;
        return l;
    }
};

// Time O(N)
class Solution {
public:
    /**
     * @param nums: an array containing n + 1 integers which is between 1 and n
     * @return: the duplicate one
     */
    int findDuplicate(vector<int> &nums) {
        int len = nums.size();

        int slow = nums[0];
        int fast = nums[nums[0]];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};