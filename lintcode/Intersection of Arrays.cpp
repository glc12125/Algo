// Divide and Conquer, time O(nlogk + klogn)
class Solution {
private:
    vector<int> divideAndConquer(const vector<vector<int>> &arrs, int start, int end) {
        if(start == end) return arrs[start];

        int mid = (start + end) / 2;
        const auto& left = divideAndConquer(arrs, start, mid);
        const auto& right = divideAndConquer(arrs, mid + 1, end);

        return merge(left, right);
    }

    vector<int> merge(const vector<int>& left, const vector<int>& right) {
        int leftSize = left.size();
        int rightSize = right.size();

        int i = 0;
        int j = 0;
        vector<int> result;
        while(i < leftSize && j < rightSize) {
            if(left[i] < right[j]) ++i;
            else if(left[i] > right[j]) ++j;
            else {
                int value = left[i];
                while(i < leftSize && value == left[++i]) {}
                while(j < rightSize && value == right[++j]) {}
                result.push_back(value);
            }
        }
        return result;
    }
public:
    /**
     * @param arrs: the arrays
     * @return: the number of the intersection of the arrays
     */
    int intersectionOfArrays(vector<vector<int>> &arrs) {
        int len = arrs.size();
        if(len == 0) return 0;
        for(auto& arr: arrs) std::sort(arr.begin(), arr.end());
        return divideAndConquer(arrs, 0, len - 1).size();
    }
};

// Hash map, time O(n*k)
class Solution{
    public:
    /**
     * @param arrs: the arrays
     * @return: the number of the intersection of the arrays
     */
    int intersectionOfArrays(vector<vector<int>> &arrs) {
        int len = arrs.size();
        if(len == 0) return 0;
        // Calling Divide and Conquer approach
        //for(auto& arr: arrs) std::sort(arr.begin(), arr.end());
        //return divideAndConquer(arrs, 0, len - 1).size();

        unordered_map<int, int> counters;
        for(const auto& arr : arrs) {
            for(auto i : arr) {
                ++counters[i];
            }
        }

        vector<int> result;
        for(auto i : counters) {
            if(i.second == len) result.push_back(i.first);
        }
        return result.size();
    }
};
