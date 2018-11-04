class Solution {
private:
    int findKth(const vector<vector<int>> &nums, int k) {
        int start = 0;
        int end = INT_MAX;

        // find the last number x that >= k numbers are >= x.
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (getGTE(nums, mid) >= k) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (getGTE(nums, start) >= k) {
            return start;
        }

        return end;
    }

    int getGTE(const vector<vector<int>> &nums, int candidate) {
        int sum = 0;
        for(const auto& line : nums) {
            sum += getGTELine(line, candidate);
        }
        return sum;
    }

    int getGTELine(const vector<int> &line, int candidate) {
        int len = line.size();
        if(len == 0) return 0;

        int start = 0;
        int end = len - 1;
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if(line[mid] >= candidate) end = mid;
            else start = mid;
        }

        if(line[start] >= candidate) return len - start;
        if(line[end] >= candidate) return len - end;

        return 0;
    }
public:
    /**
     * @param nums: the given k sorted arrays
     * @return: the median of the given k sorted arrays
     */
    double findMedian(vector<vector<int>> &nums) {
        int rowLen = nums.size();
        if(rowLen == 0) return 0.0;
        int size = 0;
        for(const auto& line : nums) {
            size += line.size();
        }

        int mid = size / 2;
        if(size % 2) return findKth(nums, mid + 1);
        else return (findKth(nums, mid + 1) * 1.0 + findKth(nums, mid) * 1.0) / 2.0;
    }
};