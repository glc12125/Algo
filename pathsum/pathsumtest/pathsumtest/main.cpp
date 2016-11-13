//
//  main.cpp
//  pathsumtest
//
//  Created by Liangchuan Gu on 25/07/2015.
//  Copyright (c) 2015 Lee Inc. All rights reserved.
//

#include <iostream>
#include <stack>

 struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };

struct TreeNodeWithState {
    TreeNode * node;
    int unvisitedChildrenNum;
    TreeNodeWithState(TreeNode* n): node(n), unvisitedChildrenNum(0){};
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == 0) {
            return false;
        }
        int currentSum = 0;
        std::stack<TreeNode*> q;
        std::stack<TreeNodeWithState> parentNodes;
        q.push(root);
        while (!q.empty()) {
            TreeNode * node = q.top();
            q.pop();
            
            currentSum += node->val;
            if (currentSum == sum) {
                if (node->left == 0 && node->right == 0) {
                    return true;
                }
            }
            
            if (node->left == 0 && node->right == 0) {
                if (parentNodes.empty()) {
                    continue;
                }
                TreeNodeWithState& parentNode = parentNodes.top();
                --(parentNode.unvisitedChildrenNum);
                currentSum -= node->val;
                if (parentNode.unvisitedChildrenNum == 0 && parentNode.node != root) {
                    currentSum -= parentNode.node->val;
                    parentNodes.pop();
                    while (parentNodes.top().node != root && parentNodes.top().unvisitedChildrenNum == 1) {
                        currentSum -= parentNodes.top().node->val;
                        parentNodes.pop();
                    }
                    
                    if (parentNodes.size() > 0) {
                        TreeNodeWithState& tmp = parentNodes.top();
                        --(tmp.unvisitedChildrenNum);
                    }
                    if ( parentNodes.top().node == root) {
                        currentSum = root->val;
                    }
                }
                
            }
            if (node->left != 0 || node->right != 0) {
                TreeNodeWithState n(node);
                
                if (node->left != 0) {
                    q.push(node->left);
                    ++(n.unvisitedChildrenNum);
                }
                if (node->right != 0) {
                    q.push(node->right);
                    ++(n.unvisitedChildrenNum);
                }
                parentNodes.push(n);
            }
            
        }
        
        return false; 
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    TreeNode * root = new TreeNode(5);
    TreeNode * rootLeft = new TreeNode(4);
    TreeNode * rootRight = new TreeNode(8);
    root->left = rootLeft;
    root->right = rootRight;
    TreeNode * tmp11 = new TreeNode(11);
    TreeNode * tmp13 = new TreeNode(13);
    TreeNode * tmp4 = new TreeNode(4);
    rootLeft->left = tmp11;
    rootRight->left = tmp13;
    rootRight->left = tmp4;
    TreeNode * tmp7 = new TreeNode(7);
    TreeNode * tmp2 = new TreeNode(2);
    TreeNode * tmp1 = new TreeNode(1);
    tmp11->left = tmp7;
    tmp11->right = tmp2;
    tmp4->right = tmp1;
    Solution s;
    if (s.hasPathSum(root, 27) == true) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "Node" << std::endl;
    }
    delete root;
    delete rootLeft;
    delete rootRight;
    delete tmp11;
    delete tmp13;
    delete tmp2;
    delete tmp4;
    delete tmp7;
    delete tmp1;
    return 0;
}
