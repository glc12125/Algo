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
    std::stack<TreeNode *> m_s;
    void createStack(TreeNode * node, double target) {
        if(node == nullptr) return;

        m_s.push(node);
        if(node->val > target) {
            createStack(node->left, target);
        } else {
            createStack(node->right, target);
        }
    }

    void nextUpper(std::stack<TreeNode *>& s) {
        auto node = s.top();

        if(node->right == 0) {
            s.pop();
            while(!s.empty() && s.top()->right == node) {
                node = s.top();
                s.pop();
            }
        } else {
            node = node->right;
            while(node != nullptr) {
                s.push(node);
                node = node->left;
            }
        }
    }

    void nextLower(std::stack<TreeNode *>& s) {
        auto node = s.top();

        if(node->left == 0) {
            s.pop();
            while(!s.empty() && s.top()->left == node) {
                node = s.top();
                s.pop();
            }
        } else {
            node = node->left;
            while(node != nullptr) {
                s.push(node);
                node = node->right;
            }
        }
    }
public:
    /**
     * @param root: the given BST
     * @param target: the given target
     * @param k: the given k
     * @return: k values in the BST that are closest to the target
     */
    vector<int> closestKValues(TreeNode * root, double target, int k) {

        createStack(root, target);
        std::stack<TreeNode*> stackCopy(m_s);

        if(m_s.top()->val > target) {
            nextLower(m_s);
        } else {
            nextUpper(stackCopy);
        }

        std::vector<int> result;
        for(int i = 0; i < k; ++i) {
            if(stackCopy.empty() || (!m_s.empty() && target - m_s.top()->val < stackCopy.top()->val - target)) {
                result.push_back(m_s.top()->val);
                nextLower(m_s);
            } else {
                result.push_back(stackCopy.top()->val);
                nextUpper(stackCopy);
            }
        }

        return result;
    }
};