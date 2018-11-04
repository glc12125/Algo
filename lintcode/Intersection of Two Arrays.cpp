// Time O(nlogn + mlogm), space O(1)
class Solution {
public:
    /**
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m == 0 || n == 0) return {};

        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        int i = 0;
        int j = 0;
        vector<int> result;
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                ++i;
            } else if(nums1[i] > nums2[j]){
                ++j;
            } else {
                int shared = nums1[i];
                result.push_back(shared);
                while(shared == nums1[++i]);
                while(shared == nums2[++j]);
            }
        }

        return result;
    }
};


// Hash Table O(m + n) (should not be O((m+n)log(n+m)), if the order of the result does not matter), space O(m + n)
class Solution {
public:
    /**
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m == 0 || n == 0) return {};

        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        vector<int> result;
        for(auto i : set1) {
            if(set2.count(i)) result.push_back(i);
        }
        std::sort(result.begin(), result.end());
        return result;
    }
};