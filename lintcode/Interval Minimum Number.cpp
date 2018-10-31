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
        int m_min;
        SegmentTreeNode* m_left;
        SegmentTreeNode* m_right;
        SegmentTreeNode(int start, int end, int min) :
                m_start(start), m_end(end), m_min(min),
                m_left(nullptr), m_right(nullptr) {}
    };

    SegmentTreeNode * build(const std::vector<int> &A, int start, int end) {
        if(start > end) return nullptr;

        SegmentTreeNode * root = new SegmentTreeNode(start, end, A[start]);
        if(start == end) return root;

        int mid = (start + end) / 2;
        root->m_left = build(A, start, mid);
        root->m_right = build(A, mid + 1, end);

        root->m_min = INT_MAX;
        if(root->m_left != nullptr)  root->m_min = std::min(root->m_min, root->m_left->m_min);
        if(root->m_right != nullptr)  root->m_min = std::min(root->m_min, root->m_right->m_min);
        return root;
    }

    int query(SegmentTreeNode * root, int start, int end) {
        if(root == nullptr) return INT_MAX;

        if(start <= root->m_start && end >= root->m_end) return root->m_min;

        int mid = (root->m_start + root->m_end) / 2;
        int leftMin = INT_MAX;
        int rightMin = INT_MAX;
        if(start <= mid) {
            if(end <= mid) leftMin = query(root->m_left, start, end);
            else leftMin = query(root->m_left, start, mid);
        }

        if(end > mid) {
            if(start > mid) rightMin = query(root->m_right, start, end);
            else rightMin = query(root->m_right, mid + 1, end);
        }

        return std::min(leftMin, rightMin);
    }

    SegmentTreeNode * m_root;
public:
    /**
     * @param A: An integer array
     * @param queries: An query list
     * @return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {

        m_root = build(A, 0, A.size() - 1);
        int len = queries.size();

        std::vector<int> result(len, INT_MAX);
        for(int i = 0; i < len; ++i) {
            result[i] = query(m_root, queries[i].start, queries[i].end);
        }
        return result;
    }
};