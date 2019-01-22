/**
 * Definition for a multi tree node.
 * struct MultiTreeNode {
 *     int val;
 *     vector<MultiTreeNode*> children;
 *     MultiTreeNode(int x) : val(x) {}
 * };
 */
class Solution {
private:
    class ResultType {
    public:
        int max_len, max_down, max_up;
        ResultType(int len, int down, int up) {
            max_len = len;
            max_down = down;
            max_up = up;
        }
    };

    ResultType helper(MultiTreeNode* root) {
        if (root == NULL) {
            return ResultType(0, 0, 0);
        }

        int down = 0, up = 0, max_len = 0;
        int total = root->children.size();
        for (auto child : root->children) {
            ResultType type = helper(child);
            max_len = max(max_len, type.max_len);
            if (child->val + 1 == root->val)
                down = max(down, type.max_down + 1);
            if (child->val - 1 == root->val)
                up = max(up, type.max_up + 1);
        }
        max_len = max(down + 1 + up, max_len);

        return ResultType(max_len, down, up);
    }
public:
    /**
     * @param root the root of k-ary tree
     * @return the length of the longest consecutive sequence path
     */
    int longestConsecutive3(MultiTreeNode* root) {
        return helper(root).max_len;
    }
};