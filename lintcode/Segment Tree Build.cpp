/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end) {
 *         this->start = start, this->end = end;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param start: start value.
     * @param end: end value.
     * @return: The root of Segment Tree.
     */
    SegmentTreeNode * build(int start, int end) {
        if(start > end) return nullptr;
        if(start == end) return new SegmentTreeNode(start, end);

        int mid = (start + end ) /2;
        SegmentTreeNode * head = new SegmentTreeNode(start, end);
        head->left = build(start, mid);
        head->right = build(mid + 1, end);
        return head;
    }
};