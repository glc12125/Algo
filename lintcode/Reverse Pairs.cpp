// Time O(NlogN), space O(N)
class Solution {
private:
    void mergeSort(std::vector<int>& nums, std::vector<int>& temp, int start, int end, long long& count) {
        if(start >= end) return;

        int mid = start + (end - start) / 2;
        mergeSort(nums, temp, start, mid, count);
        mergeSort(nums, temp, mid + 1, end, count);
        int i = start;
        int tempIndex = start;
        int j = mid + 1;
        while(i <= mid && j <= end) {
            if(nums[i] <= nums[j]) {
                temp[tempIndex++] = nums[i++];
            } else {
                temp[tempIndex++] = nums[j++];
                count += mid - i + 1;
            }
        }

        while(i <= mid) {
            temp[tempIndex++] = nums[i++];
        }

        while(j <= end) {
            temp[tempIndex++] = nums[j++];
        }

        for(int i = start; i <= end; ++i) {
            nums[i] = temp[i];
        }
    }
public:
    /**
     * @param A: an array
     * @return: total of reverse pairs
     */
    long long reversePairs(vector<int> &A) {
        int len = A.size();
        if(len == 0) return 0;
        std::vector<int> temp(len);
        long long count = 0;
        mergeSort(A, temp, 0, len - 1, count);
        return count;
    }
};

//Binary indexed tree, kept failing on [792,-300,229,-403,802,-156,819,107,924,-548,716,980,-391,47,714,-273,-267,-738,20,38,858,-511,714,533,974,677,107,241,714,-574]
class Solution {
private:
    struct Element {
        int m_val;
        int m_index;
        Element() = default;
        Element(int val, int index) : m_val(val), m_index(index) {}
    };

    struct ElementCompare {
        bool operator()(const Element& e1, const Element& e2) const {
            return e1.m_val < e2.m_val;
        }
    };

    vector<int> m_bit;

    void update(int index, int delta) {
        ++index;
        for (int i = index; i < m_bit.size(); i += lowbit(i)) {
            m_bit[i] += delta;
        }
    }

    int query(int index) {
        ++index;
        int result = 0;
        for(int i = index; i > 0; i -= lowbit(i)) {
            result += m_bit[i];
        }
        return result;
    }

    int lowbit(int i) {
        return i & (-i);
    }
public:
    /**
     * @param A: an array
     * @return: total of reverse pairs
     */
    long long reversePairs(vector<int> &A) {
        int len = A.size();
        if(len == 0) return 0;
        std::vector<Element> sortedA(len);
        for(int i = 0; i < len; ++i) {
            sortedA[i] = Element(A[i], i);
        }

        sort(sortedA.begin(), sortedA.end(), ElementCompare());
        A[sortedA[0].m_index] = 0;
        for(int i = 1; i < len; ++i) {
            if(sortedA[i].m_val == sortedA[i-1].m_val) {
                A[sortedA[i].m_index] = i - 1;
            } else {
                A[sortedA[i].m_index] = i;
            }
        }

        for(auto i : A) std::cout << i << " ";

        m_bit.resize(len + 1);
        long long count = 0;
        for(int i = 0; i < len; ++i) {
            count += query(len - 1) - query(A[i]);
            update(A[i], 1);
        }

        return count;
    }
};

// Binary Indexed Tree, find index on the fly
class Solution {
private:
    vector<int> m_bit;

    void update(int index, int delta) {
        ++index;
        for (int i = index; i < m_bit.size(); i += lowbit(i)) {
            m_bit[i] += delta;
        }
    }

    int query(int index) {
        ++index;
        int result = 0;
        for(int i = index; i > 0; i -= lowbit(i)) {
            result += m_bit[i];
        }
        return result;
    }

    int lowbit(int i) {
        return i & (-i);
    }
public:
    /**
     * @param A: an array
     * @return: total of reverse pairs
     */
    long long reversePairs(vector<int> &A) {
        int len = A.size();
        if(len == 0) return 0;
        vector<int> sortedA = A;
        sort(sortedA.begin(), sortedA.end());

        int uniqueNum = unique(sortedA.begin(), sortedA.end()) - sortedA.begin();

        m_bit.resize(uniqueNum + 1);
        long long count = 0;
        for(int i = 0; i < len; ++i) {
            A[i] = lower_bound(sortedA.begin(), sortedA.begin() + uniqueNum, A[i]) - sortedA.begin();
            count += query(uniqueNum - 1) - query(A[i]);
            update(A[i], 1);
        }

        return count;
    }
};