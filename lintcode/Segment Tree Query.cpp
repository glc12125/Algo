/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: The root of segment tree.
     * @param start: start value.
     * @param end: end value.
     * @return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode * root, int start, int end) {
        if(root->start == start && root->end == end) return root->max;

        int mid = (root->start + root->end) / 2;
        if(end <= mid && root->left != nullptr) {
            return query(root->left, start, end);
        }else if(start > mid && root->right != nullptr) {
            return query(root->right, start, end);
        } else {
            return std::max(query(root->left, start, mid), query(root->right, mid + 1, end));
        }

    }
};