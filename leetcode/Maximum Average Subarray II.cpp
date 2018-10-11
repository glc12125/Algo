class Solution {
public:
    /**
     * @param nums: an array with positive and negative numbers
     * @param k: an integer
     * @return: the maximum average
     */
    double maxAverage(vector<int> &nums, int k) {
        int len = nums.size();
        if(len < k) return 0;
        int avgSize = k;
        double maxAvg = ~(1LL<<52);
        while(avgSize <= len) {
            double ma = 0.0;
            double sum = 0.0;
            for(int i = 0; i < len; ++i) {
                double prevMa = ma;
                if(i < avgSize - 1) {
                    ma += ((double)nums[i] - prevMa) / (i + 1);
                    continue;
                } else if(i == avgSize - 1){
                    sum = (double)nums[i] + prevMa*(avgSize - 1);
                } else {
                    sum = (double)nums[i] + prevMa*avgSize;
                }
                if (i > avgSize - 1){
                    sum -= (double)nums[i - avgSize];
                }
                ma = sum / avgSize;
                maxAvg = std::max(maxAvg, ma);
            }
            ++avgSize;
        }

        return maxAvg;
    }
};

// time O(nlog(max-min))

class Solution {
public:
    /**
     * @param nums: an array with positive and negative numbers
     * @param k: an integer
     * @return: the maximum average
     */
    double maxAverage(vector<int> &nums, int k) {
        int len = nums.size();
        if(len < k) return 0;

        double start = INT_MAX;
        double end = INT_MIN;
        double eps = 1e-6;
        for(auto i : nums) {
            start = std::min(start, (double)i);
            end = std::max(end, (double)i);
        }

        double mid;
        while(start + eps < end) {
            mid = start + (end - start) / 2;
            std::vector<double> diffSums(len + 1, 0);
            for (int i = 0; i < len; ++i) {
                diffSums[i + 1] = diffSums[i] + nums[i] - mid;
            }
            double sumMax = INT_MIN;
            double diffSumMin = 0;
            for (int i = k; i < diffSums.size(); ++i) {
                sumMax = std::max(sumMax, diffSums[i] - diffSumMin);
                diffSumMin = std::min(diffSumMin, diffSums[i - k + 1]);
            }
            if (sumMax == 0) {
                return mid;
            }
            if (sumMax < 0) {
                end = mid;
                continue;
            }
            start = mid;
        }

        return start;
    }
};