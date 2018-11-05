// Time O(L+S)
class Solution {
public:
    /**
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        int aLen = A.size();
        int bLen = B.size();
        if(aLen == 0 && bLen == 0) return {};
        if(aLen == 0) return B;
        if(bLen == 0) return A;

        int a = 0;
        int b = 0;
        int index = 0;
        std::vector<int> result(aLen + bLen, 0);
        while(a < aLen && b < bLen) {
            if(A[a] < B[b]) result[index++] = A[a++];
            else result[index++] = B[b++];
        }

        while(a < aLen) result[index++] = A[a++];
        while(b < bLen) result[index++] = B[b++];

        return result;
    }
};

// Binary search on the longer array Time O(SlogL + L)
class Solution {
private:
    int findGTE(const vector<int>& longer, int target) {
        int i = 0;
        int j = longer.size() - 1;
        int mid;
        while(i + 1 < j) {
            mid = (i + j) / 2;
            if(longer[mid] < target) i = mid;
            else j = mid;
        }

        if(longer[i] >= target) return i;
        if(longer[j] >= target) return j;
        return longer.size();
    }
public:
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        int aLen = A.size();
        int bLen = B.size();
        if(aLen == 0 && bLen == 0) return {};
        if(aLen == 0) return B;
        if(bLen == 0) return A;

        auto& longer = A;
        int lLen = aLen;
        auto& shorter = B;
        int sLen = bLen;
        if(aLen < bLen) {
            std::swap(longer, shorter);
            std::swap(lLen, sLen);
        }
        int s = 0;
        int l = 0;
        int index = 0;
        std::vector<int> result(aLen + bLen, 0);
        for(int i = 0; i < sLen; ++i) {
            int position = findGTE(longer, shorter[i]);
            while(l < position) result[index++] = longer[l++];
            result[index++] = shorter[i];
        }

        while(l < lLen) result[index++] = longer[l++];

        return result;
    }
};