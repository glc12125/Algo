class Solution {
public:
    /*
     * @param nums: a sorted integer array
     * @param lower: An integer
     * @param upper: An integer
     * @return: a list of its missing ranges
     */
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        int len = nums.size();
        if(len == 0) {
            if(lower != upper) {
                return {to_string(lower) + "->" + to_string(upper)};
            } else {
                return {to_string(lower)};
            }
        }

        vector<string> result;
        if(nums[0] != lower) {
            if(nums[0] != lower + 1) {
                result.emplace_back(to_string(lower) + "->" + to_string(nums[0] - 1));
            } else {
                result.emplace_back(to_string(lower));
            }
        }

        long start = (long)nums[0] + 1;
        long end = (long)nums[0] + 1;

        for(int i = 1; i <= len; ++i) {
            if(i == len || nums[i] != (long)nums[i-1] + 1) {
                if(i != len) {
                    if(nums[i] > (long)end + 1) {
                        result.emplace_back(to_string(start) + "->" + to_string((long)nums[i] - 1));
                    } else if(nums[i] == (long)end + 1) {
                        result.emplace_back(to_string(start));
                    }
                } else {
                    if(start < upper) {
                        result.emplace_back(to_string(start) + "->" + to_string(upper));
                    } else if(start == upper){
                        result.emplace_back(to_string(start));
                    }
                }
            }
            start = (long)nums[i] + 1;
            end = (long)nums[i] + 1;
        }


        return result;
    }
};

// Cleaner version
class Solution {
private:
    void addRange(vector<string>& result, long start, long end) {
        if(start > end) return;

        if(start == end) {
            result.emplace_back(to_string(start));
        } else {
            result.emplace_back(to_string(start) + "->" + to_string(end));
        }
    }
public:
    /*
     * @param nums: a sorted integer array
     * @param lower: An integer
     * @param upper: An integer
     * @return: a list of its missing ranges
     */
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        int len = nums.size();
        vector<string> result;
        if(len == 0) {
            addRange(result, lower, upper);
            return result;
        }

        addRange(result, lower, (long)nums[0] - 1);

        for(int i = 1; i < len; ++i) {
            addRange(result, (long)nums[i-1] + 1, (long)nums[i]-1);
        }

        addRange(result, (long)nums[len - 1] + 1, upper);

        return result;
    }
};