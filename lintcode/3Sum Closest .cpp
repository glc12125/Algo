class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> &numbers, int target) {
        int len = numbers.size();
        int minDiff = INT_MAX;
        int result;
        std::sort(numbers.begin(), numbers.end());
        for(int i = 0; i < len - 2; ++i) {
            int a = numbers[i];
            int start = i + 1;
            int end = len - 1;
            int targetTwoSum = target - a;
            while(start < end) {
                int twoSum = numbers[start] + numbers[end];
                if(twoSum < targetTwoSum) {
                    if(targetTwoSum - twoSum < minDiff) {
                        minDiff = targetTwoSum - twoSum;
                        result = twoSum + a;
                    }
                    ++start;
                } else if (twoSum > targetTwoSum) {
                    if(twoSum - targetTwoSum < minDiff) {
                        minDiff = twoSum - targetTwoSum;
                        result = twoSum + a;
                    }
                    --end;
                } else return target;
            }
        }
        return result;
    }
};