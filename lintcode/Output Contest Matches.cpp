class Solution {
public:
    /**
     * @param n: a integer, denote the number of teams
     * @return: a string
     */
    string findContestMatch(int n) {
        vector<string> nums(n);
        for(int i = 1; i <= n; ++i) {
            nums[i-1] = to_string(i);
        }

        while(n > 1) {
            int half = n >> 1;
            for(int i = 0; i < half; ++i) {
                nums[i] = '(' + nums[i] + ',' + nums[n - i - 1] + ')';
            }
            n = half;
        }

        return nums[0];
    }
};

// Recursive
class Solution {
private:
    void dfs(vector<string>& nums, string& result) {
        if(nums.size() == 1) {
            result = nums[0];
            return;
        }

        int len = nums.size();
        vector<string> next;
        int l = 0;
        int r = len - l - 1;
        while(l < r) {
            next.push_back('(' + nums[l++] + ',' + nums[r--] + ')');
        }
        dfs(next, result);
    }
public:
    /**
     * @param n: a integer, denote the number of teams
     * @return: a string
     */
    string findContestMatch(int n) {
        vector<string> nums(n);
        for(int i = 1; i <= n; ++i) {
            nums[i-1] = to_string(i);
        }

        string result;
        dfs(nums, result);

        return result;
    }
};