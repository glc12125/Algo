class Solution {
public:
    /**
     * @param heights: a list of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        int left = 0;
        int right = heights.size() - 1;
        int total = 0;
        if(left >= right) return total;

        int leftHeight = heights[left];
        int rightHeight = heights[right];

        while(left < right)
        {
            if(leftHeight < rightHeight) {
                ++left;
                if(leftHeight > heights[left]) total += leftHeight - heights[left];
                else leftHeight = heights[left];
            } else {
                --right;
                if(rightHeight > heights[right]) total += rightHeight - heights[right];
                else rightHeight = heights[right];
            }
        }
        return total;
    }
};