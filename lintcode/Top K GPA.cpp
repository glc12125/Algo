class Solution {
private:
    float select(int n, std::vector<float>& nums, int start, int end) {
        if(start >= end) return nums[n];
        int i = start;
        int j = end;
        float pivot = nums[(i+j)/2];
        while(i <= j) {
            while(i <= j && nums[i] > pivot) ++i;
            while(i <= j && nums[j] < pivot) --j;
            if(i<=j) {
                float temp = nums[i];
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
    /**
     * @param list: the information of studnet
     * @param k:
     * @return: return a list
     */
    vector<vector<string>> topKgpa(vector<vector<string>> &list, int k) {
        int len = list.size();
        if(k >= len) return list;

        vector<float> gpa;
        for(const auto& grade : list) {
            gpa.push_back(stof(grade[1]));
        }

        float kPlus1Th = select(k, gpa, 0, len - 1);

        vector<vector<string>> result;
        for(const auto& grade : list) {
            if(stof(grade[1]) > kPlus1Th) {
                result.push_back(grade);
            }
        }
        return result;
    }
};