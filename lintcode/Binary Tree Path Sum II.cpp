/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
private:

    void getPath(TreeNode * root, std::vector<int>& path, int target, int level) {
        if(root == nullptr) return;

        int sum = target;
        path.push_back(root->val);
        for(int i = level; i > -1; --i) {
            sum -= path[i];
            if(sum == 0) {
                std::vector<int> result;
                for(int j = i; j < level + 1; ++j) {
                    result.push_back(path[j]);
                }
                m_results.push_back(result);
            }
        }

        getPath(root->left, path, target, level + 1);
        getPath(root->right, path, target, level + 1);
        path.pop_back();
    }

    std::vector<std::vector<int> > m_results;
public:
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> binaryTreePathSum2(TreeNode * root, int target) {
        std::vector<int> path;
        getPath(root, path, target, 0);
        return m_results;
    }
};