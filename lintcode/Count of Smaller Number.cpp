class Solution {
private:
    struct SegmentTreeNode {
        int m_start;
        int m_end;
        long long m_sum;
        SegmentTreeNode * m_left;
        SegmentTreeNode * m_right;
        SegmentTreeNode () = default;
        SegmentTreeNode(int start, int end, long long sum) :
                m_start(start) , m_end(end), m_sum(sum),
                m_left(nullptr), m_right(nullptr) {}
    };

    SegmentTreeNode * m_root;

    SegmentTreeNode * build(int start, int end, const std::vector<int>& A) {
        if(start > end) return nullptr;

        SegmentTreeNode * root = new SegmentTreeNode(start, end, A[start]);
        if(start == end) return root;

        int mid = (start + end) / 2;
        root->m_sum = 0;
        root->m_left = build(start, mid, A);
        root->m_right = build(mid + 1, end, A);
        if(root->m_left != nullptr) root->m_sum += root->m_left->m_sum;
        if(root->m_right != nullptr) root->m_sum += root->m_right->m_sum;
        return root;
    }

    long long querySegmentTree(SegmentTreeNode* root, int start, int end) {
        if(root->m_start == start && root->m_end == end) return root->m_sum;

        long long leftSum = 0;
        long long rightSum = 0;
        int mid = (root->m_start + root->m_end) / 2;
        if(start <= mid) {
            if(end <= mid) {
                leftSum = querySegmentTree(root->m_left, start, end);
            } else {
                leftSum = querySegmentTree(root->m_left, start, mid);
            }
        }

        if(mid < end){
            if(start > mid) {
                rightSum = querySegmentTree(root->m_right, start, end);
            } else {
                rightSum = querySegmentTree(root->m_right, mid + 1, end);
            }
        }

        return leftSum + rightSum;
    }
public:
    /**
     * @param A: An integer array
     * @param queries: The query list
     * @return: The number of element in the array that are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        if(A.size() == 0) return vector<int>(queries.size(), 0);
        int max = INT_MIN;
        for(auto i : A) {
            max = std::max(max, i);
        }

        std::vector<int> indexA(max + 1, 0);
        for(auto i : A) {
            ++indexA[i];
        }

        m_root = build(0, max, indexA);
        int len = queries.size();

        std::vector<int> result(len, 0);
        for(int i = 0; i < len; ++i) {
            if(queries[i] == 0) {
                result[i] = 0;
                continue;
            }
            result[i] = querySegmentTree(m_root, 0, queries[i]-1);
        }
        return result;
    }
};

// Sort and binary search
class Solution {
private:
    int bs(const std::vector<int>& A, int start, int end, int target) {

        int i = start;
        int j = end;
        int mid;
        while(i + 1 < j) {
            mid = i + (j - i) / 2;
            if(target <= A[mid]) j = mid;
            else i = mid;
        }

        if(target == A[i]) return i;
        if(target == A[j]) return j;
        if(A[i] > target) return i - 1;
        else if(A[j] < target) return j + 1;
        else return i;
    }

public:
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        int lenA = A.size();
        if(lenA == 0) return vector<int>(queries.size(), 0);

        std::sort(A.begin(), A.end());
        int len = queries.size();
        std::vector<int> result(queries.size(), 0);
        for(int i = 0; i < len; ++i) {
            int index = bs(A, 0, lenA - 1, queries[i]);
            result[i] = (A[index] == queries[i] ? index : index + 1);
        }

        return result;
    }
};