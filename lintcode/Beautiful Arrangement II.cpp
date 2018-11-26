class Solution {
public:
    /**
     * @param n: the number of integers
     * @param k: the number of distinct integers
     * @return: any of answers meet the requirment
     */
    vector<int> constructArray(int n, int k) {
        if(k >= n || n <= 0 || k <= 0) return {};
        int low = 1;
        int high = n;
        vector<int> result;
        result.push_back(high--);
        while(k > 1) {
            if(result.back() > low) {
                result.push_back(low++);
            } else {
                result.push_back(high--);
            }
            --k;
        }
        if(result.back() > low) {
            while(low <= high) {
                result.push_back(high--);
            }
        } else {
            while(low <= high) {
                result.push_back(low++);
            }
        }

        return result;
    }
};