class Solution {
private:
    vector<int> maxNumber(const vector<int>& nums, int k) {
        if(k == 0) return {};

        int len = nums.size();
        int toPop = len - k;
        vector<int> result;
        for(int i = 0; i < len; ++i) {
            int cur = nums[i];
            while (!result.empty() && cur > result.back() && toPop > 0) {
                result.pop_back();
                --toPop;
            }
            result.push_back(cur);
        }

        while(result.size() > k) {
            result.pop_back();
        }

        return result;
    }

    vector<int> maxNumber(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> result;
        auto s1 = nums1.begin();
        auto e1 = nums1.end();
        auto s2 = nums2.begin();
        auto e2 = nums2.end();

        while(s1 != e1 || s2 != e2) {
            result.push_back(
                (lexicographical_compare(s1, e1, s2, e2) ? *s2++ : *s1++)
            );
        }
        return result;
    }
public:
    /**
     * @param nums1: an integer array of length m with digits 0-9
     * @param nums2: an integer array of length n with digits 0-9
     * @param k: an integer and k <= m + n
     * @return: an integer array
     */
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        vector<int> result;
        for(int i = 0; i <= k; ++i) {
            int j = k - i;
            if(i > len1 || j > len2) {continue;}
            result = std::max(result, maxNumber(
                                        maxNumber(nums1, i), maxNumber(nums2, j)
                                    )
                             );
        }
        return result;
    }
};