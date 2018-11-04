class NumArray {
private:
    vector<int> m_bitree;
    vector<int> m_a;

    int lowbit(int x) {
        return x & (-x);
    }

    void updateBitree(int index, int value) {
        ++index;
        int delta = value - m_a[index];
        for(int i = index; i < m_bitree.size(); i += lowbit(i)) {
            m_bitree[i] += delta;
        }
    }

    int sumBitree(int index) {
        ++index;
        int result = 0;
        for(int i = index; i > 0; i -= lowbit(i)) {
            result += m_bitree[i];
        }
        return result;
    }

public:
    NumArray(vector<int> nums) {
        int len = nums.size();
        m_bitree.resize(len + 1);
        m_a.resize(len + 1);
        for(int i = 0; i < nums.size(); ++i) {
            updateBitree(i, nums[i]);
            m_a[i+1] = nums[i];
        }
    }

    void update(int i, int val) {
        updateBitree(i, val);
        m_a[i+1] = val;
    }

    int sumRange(int i, int j) {
        return sumBitree(j) - sumBitree(i - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

// Segment Tree approach
class NumArray {
private:
    struct SegmentTreeNode {
        int m_start;
        int m_end;
        int m_sum;
        SegmentTreeNode* m_left;
        SegmentTreeNode* m_right;
        SegmentTreeNode(int start, int end, int sum) : m_start(start), m_end(end),
                m_sum(sum), m_left(nullptr), m_right(nullptr) {}
    };

    SegmentTreeNode* m_root;


    SegmentTreeNode * build(const vector<int>& nums, int start, int end) {
        if(start > end) return nullptr;

        SegmentTreeNode * root = new SegmentTreeNode(start, end, nums[start]);
        if(start == end) return root;

        root->m_sum = 0;
        int mid = (root->m_start + root->m_end) / 2;
        root->m_left = build(nums, root->m_start, mid);
        root->m_right = build(nums, mid + 1, root->m_end);

        if(root->m_left != nullptr) root->m_sum += root->m_left->m_sum;
        if(root->m_right != nullptr) root->m_sum += root->m_right->m_sum;

        return root;
    }

    int query(SegmentTreeNode* root, int start, int end) {
        if(root == nullptr) return 0;
        if(start <= root->m_start && root->m_end <= end) return root->m_sum;

        int leftSum = 0;
        int rightSum = 0;
        int mid = (root->m_start + root->m_end) / 2;
        if(start <= mid) {
            if(end <= mid) {
                leftSum = query(root->m_left, start, end);
            } else {
                leftSum = query(root->m_left, start, mid);
            }
        }

        if(end > mid) {
            if(start > mid) {
                rightSum = query(root->m_right, start, end);
            } else {
                rightSum = query(root->m_right, mid + 1, end);
            }
        }

        return leftSum + rightSum;
    }

    void modify(SegmentTreeNode* root, int index, int val) {
        if(root == nullptr) return;

        if(index == root->m_start && root->m_start == root->m_end) {
            root->m_sum = val;
            return;
        }

        int mid = (root->m_start + root->m_end) / 2;
        if(index <= mid) modify(root->m_left, index, val);
        else modify(root->m_right, index, val);

        root->m_sum = 0;
        if(root->m_left != nullptr) root->m_sum += root->m_left->m_sum;
        if(root->m_right != nullptr) root->m_sum += root->m_right->m_sum;
    }
public:
    NumArray(vector<int> nums) {
        int len = nums.size();
        m_root = build(nums, 0, len - 1);
    }

    void update(int i, int val) {
        modify(m_root, i, val);
    }

    int sumRange(int i, int j) {
        return query(m_root, i, j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */