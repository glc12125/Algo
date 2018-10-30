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

    void modify(SegmentTreeNode * root, int index, int value) {
        if(root == nullptr) return;

        if(root->m_start == index && root->m_end == index) {
            root->m_sum = value;
            return;
        }

        int mid = (root->m_start + root->m_end) / 2;
        if(index <= mid) {
            modify(root->m_left, index, value);
        } else {
            modify(root->m_right, index, value);
        }

        root->m_sum = root->m_left->m_sum + root->m_right->m_sum;
    }
public:
    /* you may need to use some attributes here */

    /*
    * @param A: An integer array
    */
    Solution(vector<int> A) {
        m_root = build(0, A.size() - 1, A);
    }

    /*
     * @param start: An integer
     * @param end: An integer
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        return querySegmentTree(m_root, start, end);
    }

    /*
     * @param index: An integer
     * @param value: An integer
     * @return: nothing
     */
    void modify(int index, int value) {
        modify(m_root, index, value);
    }
};