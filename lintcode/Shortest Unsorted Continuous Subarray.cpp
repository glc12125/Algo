class Solution {
public:
    /**
     * @param nums: an array
     * @return: the shortest subarray's length
     */
    int findUnsortedSubarray(vector<int> &nums) {
        int len = nums.size();

        vector<int> copy(nums);
        std::sort(copy.begin(), copy.end());

        int startFound = -1;
        int endFound = -1;

        for(int i = 0, j = len - 1; i < len && j > -1;) {
            if(copy[i] != nums[i] && startFound == -1) {
                startFound = i;
            } else ++i;
            if(copy[j] != nums[j] && endFound == -1) {
                endFound = j;
            } else --j;
            if(startFound != -1 && endFound != -1) break;
        }
        std::cout << "startFound: " << startFound << ", endFound: " << endFound;
        return (startFound != -1 && endFound != -1) ? endFound - startFound + 1 : 0;
    }
};