// time O(N + k), space O(k)
class Solution {
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        int counter[k] = {0};

        for(auto i : colors) ++counter[i-1];
        int index = 0;
        for(int i = 0; i < k; ++i) {
            int colorCount = counter[i];
            for(int j = 0; j < colorCount; ++j) {
                colors[index + j] = i+1;
            }
            index += colorCount;
        }
    }
};

// Without extra space, time O(NlogK)
class Solution {
private:
    void select(std::vector<int>& colors, int start, int end, int colorFrom, int colorTo) {
        if(start >= end) return;
        if(colorFrom >= colorTo) return;
        int i = start;
        int j = end;
        int target = (colorTo + colorFrom) / 2;
        while(i <= j) {
            while(i <= j && colors[i] <= target) ++i;
            while(i <= j && colors[j] > target) --j;
            if(i <= j) {
                int temp = colors[i];
                colors[i] = colors[j];
                colors[j] = temp;
                ++i;
                --j;
            }
        }
        select(colors, start, j, colorFrom, target);
        select(colors, i, end, target + 1, colorTo);
    }
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        int len = colors.size();
        if(len <= 1) return;
        select(colors, 0, len - 1, 1, k);
    }
};