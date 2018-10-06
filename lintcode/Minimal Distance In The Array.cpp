class Solution {
private:
    int getElementWithMinimumAbsDiff(const std::vector<int>& a, int target) {
        int start = 0;
        int end = a.size() - 1;
        int mid;
        while(start + 1 < end) {
            mid = start + (end - start) / 2;
            if(a[mid] < target) start = mid;
            else end = mid;
        }
        //std::cout << "target: " << target << ", start: " << start << ", end: " << end << "\n";
        if(target - a[start] <= a[end] - target) return a[start];
        else return a[end];
    }
public:
    /**
     * @param a: array a
     * @param b: the query array
     * @return: Output an array of length `b.length` to represent the answer
     */
    vector<int> minimalDistance(vector<int> &a, vector<int> &b) {
        std::sort(a.begin(), a.end());
        //std::cout << "sorted a: ";
        //for(auto i : a) std::cout << i << " ";
        //std::cout << "\n";
        std::vector<int> result;
        
        for(auto i : b) {
            result.push_back(getElementWithMinimumAbsDiff(a, i));
        }
        return result;
    }
};