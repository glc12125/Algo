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
private:
    SegmentTreeNode * build(const std::vector<int> &A, int start, int end) {
        if(start > end) return nullptr;

        SegmentTreeNode * root = new SegmentTreeNode(start, end, A[start]);
        if(start == end) return root;

        int mid = (start + end) / 2;
        root->left = build(A, start, mid);
        root->right = build(A, mid + 1, end);

        root->max = INT_MIN;
        if(root->left != nullptr)  root->max = std::max(root->max, root->left->max);
        if(root->right != nullptr)  root->max = std::max(root->max, root->right->max);
        return root;
    }
public:
    /**
     * @param A: a list of integer
     * @return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int> &A) {
        return build(A, 0, A.size() - 1);
    }
};