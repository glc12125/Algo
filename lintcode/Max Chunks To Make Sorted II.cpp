// Time O(NlogN), space O(N)
class Solution {
public:
    /**
     * @param arr: an array of integers
     * @return: number of chunks
     */
    int maxChunksToSorted(vector<int> &arr) {
        int len = arr.size();
        if(len == 0) return 0;

        vector<int> sortedArr(arr);
        sort(sortedArr.begin(), sortedArr.end());

        int sumArr = 0;
        int sumSortedArr = 0;
        int answer = 0;
        for(int i = 0; i < len; ++i) {
            sumArr += arr[i];
            sumSortedArr += sortedArr[i];
            if(sumArr == sumSortedArr) {
                ++answer;
            }
        }
        return answer;
    }
};

// Time O(N), space O(N)
class Solution {
public:
    /**
     * @param arr: an array of integers
     * @return: number of chunks
     */
    int maxChunksToSorted(vector<int> &arr) {
        int len = arr.size();
        if(len == 0) return 0;

        vector<int> minToBeProcessed(arr);
        for(int i = len - 2; i > -1; --i) {
            minToBeProcessed[i] = std::min(minToBeProcessed[i], minToBeProcessed[i+1]);
        }

        int maxSoFar = INT_MIN;
        int answer = 1;
        for(int i = 0; i < len - 1; ++i) {
            maxSoFar = std::max(maxSoFar, arr[i]);
            if(maxSoFar <= minToBeProcessed[i+1]) {
                ++answer;
            }
        }
        return answer;
    }
};

// Monotonous stack, Time O(N), space O(0)
class Solution {
public:
    /**
     * @param arr: an array of integers
     * @return: number of chunks
     */
    int maxChunksToSorted(vector<int> &arr) {
        int len = arr.size();
        if(len == 0) return 0;

        stack<int> increasingStack;

        for(int i = 0; i < len; ++i) {
            if(increasingStack.empty() || increasingStack.top() <= arr[i]) {
                increasingStack.push(arr[i]);
            } else {
                int currMax = increasingStack.top();
                increasingStack.pop();
                while(!increasingStack.empty() && increasingStack.top() > arr[i]) {
                    increasingStack.pop();
                }
                increasingStack.push(currMax);
            }
        }
        return increasingStack.size();
    }
};

