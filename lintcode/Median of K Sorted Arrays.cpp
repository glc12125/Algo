// Double Binary search, time O(KM + logINT_MAX*K*logM), space O(1)
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

// Heap, time O(klogK + K*M*logK), worse than the previous double binary search
class Solution {
private:
    struct Num {
        int m_val;
        int m_rIndex;
        int m_index;
        Num () = default;
        Num(int val, int rIndex, int index) : m_val(val), m_rIndex(rIndex), m_index(index) {}
    };

    struct NumCompare {
        bool operator()(const Num& n1, const Num& n2) const {
            return n1.m_val > n2.m_val;
        }
    };
public:
    double findMedian(vector<vector<int>> &nums) {
        int rowLen = nums.size();
        if(rowLen == 0) return 0.0;

        std::priority_queue<Num, std::vector<Num>, NumCompare> q;
        int count = 0;
        for(int i = 0; i < rowLen; ++i) {
            if(nums[i].empty()) continue;
            q.push(Num(nums[i][0], i, 0));
            count += nums[i].size();
        }

        bool isEven = count % 2 == 0;
        int mid = count / 2;
        double sum = 0;
        double result = 0;
        for(int i = 0; i <= mid; ++i) {
            auto num = q.top();
            q.pop();
            if(isEven) {
                if(i >= mid - 1) sum += num.m_val;
            } else {
                if(i == mid) sum = num.m_val;
            }

            if(num.m_index + 1 < nums[num.m_rIndex].size()) q.push(Num(nums[num.m_rIndex][num.m_index + 1], num.m_rIndex, num.m_index + 1));
        }

        if(isEven) {
            return sum / 2.0;
        } else {
            return sum;
        }
    }
};