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

// Traversal iterative
class Solution {
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        TreeNode * curr = root;
        std::stack<TreeNode*> s;

        int rank = 1;
        while(curr != nullptr || !s.empty()) {
            if(curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            } else {
                curr = s.top();
                s.pop();
                if(rank++ == k) return curr->val;
                curr = curr->right;
            }
        }
    }
};

//Traversal, recursive
class Solution {
private:
    void inOrder(TreeNode* node, int k, int& rank, int&result){
        if(node == nullptr) return;
        inOrder(node->left, k, rank, result);
        if(rank++ == k) {
            result = node->val;
            return;
        }
        inOrder(node->right, k, rank, result);
    }
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        int rank = 1;
        int result = 0;
        inOrder(root, k, rank, result);
        return result;
    }
};


// Divide and conquer
class Solution {
private:
    std::stack<TreeNode *> m_s;

    void initialize(TreeNode * root) {
        while(root != nullptr) {
            m_s.push(root);
            root = root->left;
        }
    }

    bool hasNext() {
        return !m_s.empty();
    }

    TreeNode * next() {
        auto curr = m_s.top();
        auto node = curr;

        if(node->right == nullptr) {
            node = m_s.top();
            m_s.pop();
            while(!m_s.empty() && node == m_s.top()->right) {
                node = m_s.top();
                m_s.pop();
            }
        } else {
            node = node->right;
            while(node != nullptr) {
                m_s.push(node);
                node = node->left;
            }
        }
        return curr;
    }
public:
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        initialize(root);

        int result = -1;
        for(int i = 0; i < k; ++i) {
            if(hasNext()) {
                result = next()->val;
            } else {return -1;}
        }
        return result;
    }
};