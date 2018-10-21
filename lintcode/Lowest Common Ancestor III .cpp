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
    struct ResultType{
        bool m_foundA;
        bool m_foundB;
        TreeNode * m_lca;

        ResultType() : m_foundA(false), m_foundB(false), m_lca(nullptr) {
        }

        ResultType(bool foundA, bool foundB, TreeNode* lca) : m_foundA(foundA), m_foundB(foundB), m_lca(lca) {
        }
    };

    ResultType findLca(TreeNode * root, TreeNode * A, TreeNode * B) {
        if(root == nullptr) {
            return ResultType(false, false, nullptr);
        }

        auto leftResult = findLca(root->left, A, B);
        auto rightResult = findLca(root->right, A, B);

        if(leftResult.m_lca || rightResult.m_lca) {
            ResultType result;
            if(leftResult.m_lca != nullptr) result.m_lca = leftResult.m_lca;
            else result.m_lca = rightResult.m_lca;
            return result;
        }

        if((leftResult.m_foundA || leftResult.m_foundB) && (rightResult.m_foundA || rightResult.m_foundB)) {
            ResultType result(leftResult.m_foundA || rightResult.m_foundA, leftResult.m_foundB || rightResult.m_foundB, root);
            return result;
        }

        bool rootMatch = root->val == A->val || root->val == B->val;
        if(leftResult.m_foundA || leftResult.m_foundB) {
            ResultType result(leftResult.m_foundA, leftResult.m_foundB, rootMatch? root : nullptr);
            return result;
        }

        if(rightResult.m_foundA || rightResult.m_foundB) {
            ResultType result(rightResult.m_foundA, rightResult.m_foundB, rootMatch? root : nullptr);
            return result;
        }

        ResultType result;
        if(root->val == A->val) result.m_foundA = true;
        if(root->val == B->val) result.m_foundB = true;
        if(result.m_foundA && result.m_foundB) result.m_lca = root;
        return result;

    }
public:
    /*
     * @param root: The root of the binary tree.
     * @param A: A TreeNode
     * @param B: A TreeNode
     * @return: Return the LCA of the two nodes.
     */
    TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
        auto result = findLca(root, A, B);
        return result.m_lca;
    }
};



// Similar approach but cleaner
class Solution {
private:
    struct ResultType{
        bool m_foundA;
        bool m_foundB;
        TreeNode * m_node;

        ResultType() : m_foundA(false), m_foundB(false), m_node(nullptr) {
        }

        ResultType(bool foundA, bool foundB, TreeNode* node) : m_foundA(foundA), m_foundB(foundB), m_node(node) {
        }
    };

    ResultType findLca(TreeNode * root, TreeNode * A, TreeNode * B) {
        if(root == nullptr) {
            return ResultType(false, false, nullptr);
        }

        auto leftResult = findLca(root->left, A, B);
        auto rightResult = findLca(root->right, A, B);

        bool foundA = leftResult.m_foundA || rightResult.m_foundA || root->val == A->val;
        bool foundB = leftResult.m_foundB || rightResult.m_foundB || root->val == B->val;

        if(root->val == A->val || root->val == B->val) {
            return ResultType(foundA, foundB, root);
        }

        if(leftResult.m_node != nullptr && rightResult.m_node != nullptr) {
            return ResultType(foundA, foundB, root);
        }
        if(leftResult.m_node != nullptr ) {
            return ResultType(foundA, foundB, leftResult.m_node);
        }
        if(rightResult.m_node != nullptr ) {
            return ResultType(foundA, foundB, rightResult.m_node);
        }

    }
public:
    /*
     * @param root: The root of the binary tree.
     * @param A: A TreeNode
     * @param B: A TreeNode
     * @return: Return the LCA of the two nodes.
     */
    TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
        auto result = findLca(root, A, B);
        if(result.m_foundA && result.m_foundB) return result.m_node;
        else return nullptr;
    }
};