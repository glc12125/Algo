class Solution {
private:
    void reverseFromIndex(vector<int> &nums, int index, int end) {
        for(int i = index, j = end; i < j; ++i, --j){
            std::swap(nums[i], nums[j]);
        }
    }
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers
     */
    vector<int> nextPermutation(vector<int> &nums) {
        int len = nums.size();
        if(len == 0) return {};
        if(len == 1) return nums;

        int firstDecending = -1;
        for(int i = len - 1; i > 0; --i) {
            if(nums[i] > nums[i-1]) {
                firstDecending = i - 1;
                break;
            }
        }
        if(firstDecending != -1) {
            for(int i = len - 1; i > firstDecending; --i) {
                if(nums[i] > nums[firstDecending]) {
                    std::swap(nums[firstDecending], nums[i]);
                    break;
                }
            }
        }

        reverseFromIndex(nums, firstDecending + 1, len - 1);
        return nums;
    }
};

//
class Solution {
private:
    void dfs(const vector<int>& digits, const string& target, string current, vector<string>& allTimes, int& index){
         if(current.size() == 5) {
             if(target == current) {
                 index = allTimes.size();
             }
             allTimes.push_back(current);
             return;
         }
         if(current.size() == 2) {
             current += ':';
         }

         int len = current.size();
         for(int i = 0; i < 4; ++i) {
             if(len == 0 && digits[i] > 2) {continue;}
             if(len == 1 && current[0] == '2' && digits[i] > 4) {continue;}
             if(len == 3 && digits[i] > 5) {continue;}
             dfs(digits, target, current + to_string(digits[i]), allTimes, index);
         }
    }

public:
    /**
     * @param time: the given time
     * @return: the next closest time
     */
    string nextClosestTime(string &time) {
        vector<int> digits(4, 0);

        digits[0] = time.at(0) - '0';
        digits[1] = time.at(1) - '0';
        digits[2] = time.at(3) - '0';
        digits[3] = time.at(4) - '0';

        sort(digits.begin(), digits.end());

        vector<string> allTimes;
        int index = -1;
        dfs(digits, time, "", allTimes, index);

        //下一个时间便是答案
        index = (index + 1) % allTimes.size();

        return allTimes[index];
    }
};