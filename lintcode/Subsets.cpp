class Solution {
private:
    void btFind(const std::vector<int>& nums, int startIndex,
                std::vector<int>& subset, std::vector<std::vector<int> >& result) {
        result.push_back(subset);
        int size = nums.size();
        for(int i = startIndex; i < size; ++i) {
            subset.push_back(nums[i]);
            btFind(nums, i + 1, subset, result);
            subset.pop_back();
        }
    }
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        std::vector<std::vector<int> > result;
        int size = nums.size();
        if(size == 0) return {{}};

        std::sort(nums.begin(), nums.end());

        std::vector<int> subset;
        btFind(nums, 0, subset, result);
        return result;
    }
};

// Iterative, simulate the function call stack
class Solution {
private:
    void btFind(const std::vector<int>& nums, int startIndex,
                std::vector<int>& subset, std::vector<std::vector<int> >& result) {
        result.push_back(subset);
        int size = nums.size();
        for(int i = startIndex; i < size; ++i) {
            subset.push_back(nums[i]);
            btFind(nums, i + 1, subset, result);
            subset.pop_back();
        }
    }
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        std::vector<std::vector<int> > result;
        int size = nums.size();
        if(size == 0) return {{}};

        std::sort(nums.begin(), nums.end());

        std::vector<int> subset;
        //btFind(nums, 0, subset, result);

        std::stack<std::vector<int> > s;
        std::stack<int> indexS;

        s.push(subset);
        indexS.push(0);

        while(!s.empty()) {
            auto set = s.top();
            s.pop();
            result.push_back(set);
            auto index = indexS.top();
            indexS.pop();
            for(int j = index; j < size; ++j) {
                std::vector<int> temp(set);
                temp.push_back(nums[j]);
                s.push(temp);
                indexS.push(j+1);
            }
        }
        return result;
    }
};