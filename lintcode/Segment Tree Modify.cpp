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
     * @param index: index.
     * @param value: value
     * @return: nothing
     */
    void modify(SegmentTreeNode * root, int index, int value) {
        if(root == nullptr) return;

        std::stack<SegmentTreeNode*> s;
        SegmentTreeNode * curr = root;
        while(curr != nullptr) {
            int mid = (curr->start + curr->end) / 2;
            s.push(curr);
            if(index <= mid) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        curr = s.top();
        curr->max = value;
        s.pop();
        while(!s.empty()) {
            curr = s.top();
            curr->max = std::max(curr->left->max, curr->right->max);
            s.pop();
        }
    }
};