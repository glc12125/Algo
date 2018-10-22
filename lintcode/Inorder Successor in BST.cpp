/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
private:
    std::stack<TreeNode*> m_s;

    void createStack(TreeNode* root, TreeNode* p) {
        if(root == nullptr || p == nullptr) return;

        while(root != nullptr) {
            m_s.push(root);
            if(p->val < root->val) root = root->left;
            else root = root->right;
        }
    }

    TreeNode * successor(){
        if(m_s.empty()) return nullptr;
        auto curr = m_s.top();
        auto node = curr;

        if(node->right == nullptr) {
            m_s.pop();
            while(!m_s.empty() && m_s.top()->right == node) {
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
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        createStack(root, p);
        if(m_s.empty()) return nullptr;

        auto result = successor();
        while(result != nullptr && result->val <= p->val) result = successor();
        return result;
    }
};


// Version 2
class Solution {
private:
    std::stack<TreeNode*> m_s;
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        if(root == nullptr || p == nullptr) return nullptr;

        while(root != nullptr && root != p) {
            m_s.push(root);
            if(p->val < root->val) root = root->left;
            else root = root->right;
        }

        if(root == nullptr) return nullptr;

        m_s.push(p);
        if(m_s.empty()) return nullptr;

        auto node = m_s.top();

        if(node->right == nullptr) {
            m_s.pop();
            while(!m_s.empty() && m_s.top()->right == node) {
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

        return m_s.empty() ? nullptr : m_s.top();
    }
};

// Iterative traversal
class Solution {
private:
    std::stack<TreeNode*> m_s;
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        if(root == nullptr || p == nullptr) return nullptr;

        std::stack<TreeNode*> s;
        auto node = root;
        TreeNode * successor = nullptr;
        bool foundP = false;
        while(node != nullptr || !s.empty()) {
            while(node != nullptr) {
                s.push(node);
                node = node->left;
            }

            node = s.top();
            s.pop();
            if(foundP){
                return node;
            }
            if(node->val == p->val) {
                foundP = true;
            }
            node = node->right;
        }
        return nullptr;
    }
};

// Recursive Traversal
class Solution {
private:
    TreeNode * m_suc = nullptr;

    void inOrder(TreeNode * root, TreeNode * p) {
        if(root == nullptr) return;

        if(root->val == p->val) {
            if(root->right != nullptr) {
                root = root->right;
                while(root != nullptr) {
                    m_suc = root;
                    root = root->left;
                }
            }
        } else if (root->val > p->val) {
            m_suc = root;
            inOrder(root->left, p);
        } else {
            inOrder(root->right, p);
        }
    }
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        if(root == nullptr || p == nullptr) return nullptr;

        inOrder(root, p);
        return m_suc;
    }
};