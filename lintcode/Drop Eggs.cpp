class Solution {
public:
    /**
     * @param n: An integer
     * @return: The sum of a and b
     */
    int dropEggs(int n) {
        long times = 0;
        for(int i = 1;; ++i) {
            times += i;
            if(times >= n) return i;
        }
    }
};

// Feeling like binary search

class Solution {
public:
    /**
     * @param n: An integer
     * @return: The sum of a and b
     */
    int dropEggs(int n) {
        // write your code here
        long index = 1;
        int result;
        while ((index + 1) * index / 2 < n) {
            index *= 2;
        }

        result = firstIndex(n, index);
        return result;
    }

private:
    int firstIndex(int n, int index) {
        long start = 1, end = index;
        while (start + 1 < end) {
            long mid = start + (end - start) / 2;
            if (mid * (mid + 1) / 2 < n) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if (start * (start + 1) / 2 >= n) {
            return static_cast<int>(start);
        }
        if (end * (end + 1) / 2 >= n) {
            return static_cast<int>(end);
        }
    }
};