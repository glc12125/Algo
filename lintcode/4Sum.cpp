class Solution {
public:
    /**
     * @param numbers: Give an array
     * @param target: An integer
     * @return: Find all unique quadruplets in the array which gives the sum of zero
     */
    vector<vector<int>> fourSum(vector<int> &numbers, int target) {
        int len = numbers.size();
        std::sort(numbers.begin(), numbers.end());
        std::vector<std::vector<int> > result;
        for(int i = 0; i < len - 3; ++i) {
            int a = numbers[i];
            if(i > 0 && a == numbers[i-1]) continue;
            for(int j = i + 1; j < len - 2; ++j) {
                int b = numbers[j];
                if(j > i + 1 && b == numbers[j-1]) continue;
                int targetTwoSum = target - a - b;
                int start = j + 1;
                int end = len - 1;
                while (start < end) {
                    int twoSum = numbers[start] + numbers[end];
                    if(twoSum < targetTwoSum) {
                        ++start;
                    } else if (twoSum > targetTwoSum) {
                        --end;
                    } else {
                        result.push_back({a, b, numbers[start], numbers[end]});
                        ++start;
                        --end;
                        while(start < end && numbers[start] == numbers[start - 1]) ++start;
                        while(start < end && numbers[end] == numbers[end + 1]) --end;
                    }
                }
            }
        }
        return result;
    }
};