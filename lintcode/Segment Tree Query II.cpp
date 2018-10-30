/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: The root of segment tree.
     * @param start: start value.
     * @param end: end value.
     * @return: The count number in the interval [start, end]
     */
    int query(SegmentTreeNode * root, int start, int end) {
        if(root == nullptr || start > end) return 0;

        if(start <= root->start && end >= root->end) return root->count;

        int leftCount = 0;
        int rightCount = 0;
        int mid = (root->start + root->end) / 2;
        if(start <= mid) {
            if(end <= mid) {
                leftCount = query(root->left, start, end);
            } else {
                leftCount = query(root->left, start, mid);
            }
        }

        if(end > mid) {
            if(start > mid) {
                rightCount = query(root->right, start, end);
            } else {
                rightCount = query(root->right, mid + 1, end);
            }
        }

        return leftCount + rightCount;
    }
};