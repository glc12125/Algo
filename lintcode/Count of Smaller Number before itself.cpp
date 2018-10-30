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

    void increaseValue(SegmentTreeNode * root, int index) {
        if(root == nullptr) return;

        if(root->m_start == index && root->m_end == index) {
            ++root->m_sum;
            return;
        }

        int mid = (root->m_start + root->m_end) / 2;
        if(index <= mid) {
            increaseValue(root->m_left, index);
        } else {
            increaseValue(root->m_right, index);
        }

        root->m_sum = root->m_left->m_sum + root->m_right->m_sum;
    }
public:
    /**
     * @param A: an integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        if(A.size() == 0) return {};
        int max = INT_MIN;
        for(auto i : A) {
            max = std::max(max, i);
        }

        std::vector<int> indexA(max + 1, 0);
        m_root = build(0, max, indexA);

        int len = A.size();
        std::vector<int> result(len, 0);
        for(int i = 1; i < len; ++i) {
            increaseValue(m_root, A[i-1]);
            if(A[i] == 0) {
                result[i] = 0;
                continue;
            }
            result[i] = querySegmentTree(m_root, 0, A[i]-1);
        }
        return result;
    }

};