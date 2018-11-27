// Two pointers from middle global minimum/maximum to two sides
class Solution {
private:
    int getFirstGTE(const vector<int>& nums, int start, int end, float target) {
        int i = 0;
        int j = end;
        while(i + 1 < j) {
            int mid = i + (j - i)/2;
            if(nums[mid] < target) i = mid;
            else j = mid;
        }

        if(nums[i] >= target) return i;
        if(nums[j] >= target) return j;
        return nums.size();
    }

    int calc(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }

public:
    /**
     * @param nums: a sorted array
     * @param a:
     * @param b:
     * @param c:
     * @return: a sorted array
     */
    vector<int> sortTransformedArray(vector<int> &nums, int a, int b, int c) {
        int len = nums.size();
        vector<int> result;
        if((a == 0 && b > 0) || (a == 0 && b == 0)) {
            for(int i = 0; i < len; ++i) {
                result.push_back(calc(nums[i], a, b, c));
            }
            return result;
        }
        if(a == 0 && b < 0) {
            for(int i = len - 1; i >= 0; --i) {
                result.push_back(calc(nums[i], a, b, c));
            }
            return result;
        }


        float minOmax = (float)-b / (a + a);
        int pos = getFirstGTE(nums, 0, len - 1, minOmax);
        int smaller = pos - 1;
        int bigger = pos;

        while(smaller >= 0 || bigger < len) {
            if(smaller >= 0 && (bigger < len && (minOmax - nums[smaller]) < (nums[bigger] - minOmax)) || (bigger >= len)) {
                result.push_back(calc(nums[smaller--], a, b, c));
            } else if (bigger < len) {
                result.push_back(calc(nums[bigger++], a, b, c));
            }
        }

        if(a < 0) reverse(result.begin(), result.end());
        return result;
    }
};

// Two pointers from two sides to middle
class Solution {
private:
    int calc(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }

public:
    /**
     * @param nums: a sorted array
     * @param a:
     * @param b:
     * @param c:
     * @return: a sorted array
     */
    vector<int> sortTransformedArray(vector<int> &nums, int a, int b, int c) {
        vector<int> rst;
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            int y1 = calc(nums[i], a, b, c);
            int y2 = calc(nums[j], a, b, c);
            if (a >= 0) {
                if (y1 >= y2) {
                    rst.push_back(y1);
                    i++;
                } else {
                    rst.push_back(y2);
                    j--;
                }
            } else {
                if (y1 < y2) {
                    rst.push_back(y1);
                    i++;
                } else {
                    rst.push_back(y2);
                    j--;
                }
            }
        }

        if (rst.size() > 0 && rst.front() > rst.back()) {
            reverse(rst.begin(), rst.end());
        }

        return rst;
    }
};