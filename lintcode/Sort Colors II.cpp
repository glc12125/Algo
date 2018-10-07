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