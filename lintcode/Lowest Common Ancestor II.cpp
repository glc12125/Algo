/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */


class Solution {
public:
    /*
     * @param root: The root of the tree
     * @param A: node in the tree
     * @param B: node in the tree
     * @return: The lowest common ancestor of A and B
     */
    ParentTreeNode * lowestCommonAncestorII(ParentTreeNode * root, ParentTreeNode * A, ParentTreeNode * B) {
        if(root == nullptr) return nullptr;

        std::unordered_set<ParentTreeNode*> discovered;
        auto node = A;
        while(node != nullptr) {
            discovered.insert(node);
            node = node->parent;
        }

        node = B;
        while(node != nullptr) {
            if(discovered.count(node) > 0) return node;
            discovered.insert(node);
            node = node->parent;
        }

        return nullptr;
    }
};

// Recursive
class Solution {
private:
    ParentTreeNode * populateParent(ParentTreeNode * root, std::unordered_set<ParentTreeNode*>& discovered) {
        if(root == nullptr) return nullptr;
        if(discovered.count(root) > 0) return root;
        discovered.insert(root);
        root = root->parent;
        populateParent(root, discovered);
    }
public:
    /*
     * @param root: The root of the tree
     * @param A: node in the tree
     * @param B: node in the tree
     * @return: The lowest common ancestor of A and B
     */
    ParentTreeNode * lowestCommonAncestorII(ParentTreeNode * root, ParentTreeNode * A, ParentTreeNode * B) {
        std::unordered_set<ParentTreeNode*> discovered;
        auto found = populateParent(A, discovered);
        if(found != nullptr) return found;
        found = populateParent(B, discovered);
        return found;
    }
};