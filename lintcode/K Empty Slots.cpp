// Time O(NlogN), space O(N), Time out
class Solution {
public:
    /**
     * @param flowers: the place where the flower will open in that day
     * @param k:  an integer
     * @return: in which day meet the requirements
     */
    int kEmptySlots(vector<int> &flowers, int k) {
        int len = flowers.size();
        if(k + 2 > len) {
            return -1;
        }

        set<int> container;
        for(int i = 0; i < len; ++i) {
            int x = flowers[i];
            auto l = container.insert(x).first;
            auto r = l;

            if(++r != container.end() && *r == x + k + 1) {
                return i + 1;
            }

            if(l != container.begin() && *(--l) == x - k - 1) {
                return i + 1;
            }
        }
        return -1;
    }
};

// Time O(N^2logN), space O(N), Time out
class Solution {
private:
    struct SegmentTreeNode {
        int m_start;
        int m_end;
        int m_bloomingCount;
        SegmentTreeNode * m_left;
        SegmentTreeNode * m_right;
        SegmentTreeNode(int start, int end, int bloomingCount) :
            m_start(start), m_end(end), m_bloomingCount(bloomingCount),
            m_left(nullptr), m_right(nullptr) {}
    };

    SegmentTreeNode* build(int start, int end) {
        if(start > end) return nullptr;

        SegmentTreeNode * root = new SegmentTreeNode(start, end, 0);
        if(start == end) return root;

        int mid = (start + end) / 2;
        root->m_left = build(start, mid);
        root->m_right = build(mid + 1, end);
        if(root->m_left != nullptr) root->m_bloomingCount += root->m_left->m_bloomingCount;
        if(root->m_right != nullptr) root->m_bloomingCount += root->m_right->m_bloomingCount;
        return root;
    }

    void modify(SegmentTreeNode* root, int index) {
        if(root == nullptr) return;
        if(root->m_start == index && root->m_end == index) {
            root->m_bloomingCount = 1;
            return;
        }

        int mid = (root->m_start + root->m_end) / 2;
        if(index <= mid) {
            modify(root->m_left, index);
        } else {
            modify(root->m_right, index);
        }

        root->m_bloomingCount = root->m_left->m_bloomingCount + root->m_right->m_bloomingCount;
    }

    int query(SegmentTreeNode * root, int start, int end) {
        if(root == nullptr || start > end) {
            return 0;
        }

        if(start <= root->m_start && end >= root->m_end) {
            return root->m_bloomingCount;
        }

        int leftCount = 0;
        int rightCount = 0;
        int mid = (root->m_start + root->m_end) / 2;
        if(start <= mid) {
            if(end <= mid) {
                leftCount = query(root->m_left, start, end);
            } else {
                leftCount = query(root->m_left, start, mid);
            }
        }

        if(end > mid) {
            if(start > mid) {
                rightCount = query(root->m_right, start, end);
            } else {
                rightCount = query(root->m_right, mid + 1, end);
            }
        }

        return leftCount + rightCount;
    }
public:
    /**
     * @param flowers: the place where the flower will open in that day
     * @param k:  an integer
     * @return: in which day meet the requirements
     */
    int kEmptySlots(vector<int> &flowers, int k) {
        int len = flowers.size();
        if(k + 2 > len) {
            return -1;
        }

        auto root = build(0, len - 1);
        for(int i = 0; i < len; ++i) {
            if(i < 2) {
                modify(root, flowers[i]-1);
                continue;
            }
            int max = len - (k + 2);
            for(int start = 0; start <= max; ++start) {
                int end = start + k + 1;
                bool leftBlooming = (query(root, start, start) == 1);
                bool rightBlooming = (query(root, end, end) == 1);
                bool kNotBlooming = (query(root, start, end) == 2);
                if(leftBlooming && rightBlooming && kNotBlooming) {
                    return i;
                }
            }
            modify(root, flowers[i]-1);
        }
        return -1;
    }
};

