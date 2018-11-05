// Time O(N + M)
class Solution {
public:
    /**
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int,int> counters;
        for(auto i : nums1) {
            ++counters[i];
        }

        vector<int> result;
        for(auto i : nums2) {
            if(counters.count(i)) {
                result.push_back(i);
                if(--counters[i] == 0) counters.erase(i);
            }
        }
        return result;
    }
};

// Time O(NlogN + MlogM + M + N)
class Solution {
        vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(len1 == 0 || len2 == 0) return {};

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0;
        int j = 0;
        vector<int> result;
        while(i < len1 && j < len2) {
            if(nums1[i] < nums2[j]) ++i;
            else if(nums1[i] > nums2[j]) ++j;
            else {
                result.push_back(nums1[i]);
                ++i;
                ++j;
            }
        }
        return result;
    }
};