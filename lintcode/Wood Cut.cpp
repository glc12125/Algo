class Solution {
public:
    /**
     * @param L: Given n pieces of wood with length L[i]
     * @param k: An integer
     * @return: The maximum length of the small pieces
     */
    int woodCut(vector<int> &L, int k) {
        int n = L.size();
        if(n == 0) return 0;
        if(k < 1) return 0;

        int left = 1;
        int right = *std::max_element(L.begin(), L.end());
        int mid;
        while(left + 1 < right) {
            int total = 0;
            mid = left + (right - left) / 2;
            for(auto wood : L) total += wood / mid;
            if(total < k) right = mid;
            else left = mid;
        }

        int total = 0;
        for(auto wood : L) total += wood / right;
        if(total >= k) return right;
        total = 0;
        for(auto wood : L) total += wood / left;
        if(total >= k) return left;

        return 0;
    }
};