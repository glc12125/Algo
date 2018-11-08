// Time O(N^2), which will time out if the test case is too big
class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        int len = height.size();
        if(len == 0) return 0;
        if(len == 1) return height[0];

        int maxArea = INT_MIN;
        for(int i = 0; i < len; ++i) {
            int left = i;
            int right = i;
            while(left > - 1 && height[left] >= height[i]){ --left; }
            while(right < len && height[right] >= height[i]) { ++right; }
            maxArea = std::max((right - left - 1) * height[i], maxArea);
        }

        return maxArea;
    }
};

// Monotonous Stack Time O(N)
class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        int len = height.size();
        if(len == 0) return 0;


        stack<int> indexStack;
        int maxArea = 0;
        for(int i = 0; i <= len; ++i) {
            int curr = (i == len ? -1 : height[i]);
            while(!indexStack.empty() && curr <= height[indexStack.top()]) {
                int h = height[indexStack.top()];
                indexStack.pop();
                // We can calculate the width because the index matched height in stack is increasing for sure,
                // So we just need to find the first height that is less than the top of the stack and calculate
                int w = indexStack.empty() ? i : i - indexStack.top() - 1;
                maxArea = std::max(w * h, maxArea);
            }
            indexStack.push(i);
        }

        return maxArea;
    }
};