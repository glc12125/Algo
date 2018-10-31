/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

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
     * @param A: An integer list
     * @param queries: An query list
     * @return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        m_root = build(0, A.size() - 1, A);

        int len = queries.size();
        std::vector<long long> result(len, 0);
        for(int i = 0; i < len; ++i) {
            result[i] = querySegmentTree(m_root, queries[i].start, queries[i].end);
        }
        return result;
    }
};