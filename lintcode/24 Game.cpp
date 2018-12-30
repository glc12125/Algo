class Solution {
private:
    double EPS = 1e-6;
    char m_operators[4] = {'*', '/', '+', '-'};

    bool dfs(const vector<double>& nums) {
        int len = nums.size();

        if(len == 1) {
            if(abs(nums[0] - 24) < EPS) {return true;}
            else {return false;}
        }

        for(int i = 0; i < len; ++i) {
            for(int j = i + 1; j < len; ++j) {
                for(auto op : m_operators) {
                    auto nextNums = getNextNums(nums, i, j);
                    if(op != '/' || (op == '/' && abs(nums[j]) > EPS)) {
                        double result = calculate(nums[i], nums[j], op);
                        nextNums.push_back(result);
                        if(dfs(nextNums)) { return true;}
                        nextNums.pop_back();
                    }

                    if(op == '-' || (op == '/' && abs(nums[i]) > EPS)) {
                        double result = calculate(nums[j], nums[i], op);
                        nextNums.push_back(result);
                        if(dfs(nextNums)) { return true;}
                    }
                }
            }
        }

        return false;
    }

    double calculate(double x, double y, char op) {
        switch (op) {
            case '*': {
                return x * y;
            } case '/' : {
                return x / y;
            } case '+' : {
                return x + y;
            } case '-' : {
                return x - y;
            }
        }
    }

    vector<double> getNextNums(const vector<double>& nums, int i, int j) {
        vector<double> nextNumArray;
        int len = nums.size();
        for(int k = 0; k < len; ++k) {
            if(k != i && k != j) {
                nextNumArray.push_back(nums[k]);
            }
        }
        return nextNumArray;
    }
public:
    /**
     * @param nums: 4 cards
     * @return: whether they could get the value of 24
     */
    bool compute24(vector<double> &nums) {
        return dfs(nums);
    }
};