//
//  main.cpp
//  K_Empty_Slots.leetcode
//
//  Created by Liangchuan Gu on 12/12/2017.
//  Copyright © 2017 Liangchuan Gu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    struct Node {
        Node * _left;
        Node * _right;
        Node * _parent;
        int _val;
        Node(int v) : _left(nullptr), _right(nullptr), _parent(nullptr), _val(v) {}
    };
    
    struct BST {
        Node * _root;
        int _k;
        BST(int k) : _root(nullptr), _k(k) {}
        
        bool insert(int val)
        {
            Node *ptr = nullptr;
            Node *ptr_parent = nullptr;
            
            bool result = false;
            if(_root == nullptr)
            {//The BST is Empty...
                Node *newNode = new Node(val);
                _root = newNode;
                ptr = _root;
            } else { //traversing the tree to find the insertion point
                ptr = _root;
                while(ptr != nullptr)
                {
                    if((ptr -> _val) == val) {return false;} // this cannot happen
                    
                    if(val < (ptr -> _val))
                    {
                        ptr_parent = ptr;
                        ptr = ptr -> _left;
                    } else {
                        ptr_parent = ptr;
                        ptr = ptr -> _right;
                    }
                }
                Node *newNode = new Node(val);
                newNode->_parent = ptr_parent;
                //checking for parent value to determine if
                //the Node is a left or right child
                if(val < (ptr_parent -> _val)){
                    ptr_parent -> _left = newNode;
                    // Find predecessor
                    if(ptr_parent->_val == (val + _k + 1)) {
                        result = true;
                    } else {
                        // Find successor
                        Node * successor = ptr_parent;
                        while(successor->_parent && successor->_val > val) {
                            successor = successor->_parent;
                        }
                        if(successor->_val == (val - _k - 1)) {
                            result = true;
                        }
                    }
                    
                }
                else{
                    ptr_parent -> _right = newNode;
                    if(ptr_parent->_val == val - _k - 1) {
                        result = true;
                    } else {
                        // Find precedent
                        Node * predecessor = ptr_parent;
                        while(predecessor->_parent && predecessor->_val < val) {
                            predecessor = predecessor->_parent;
                        }
                        // Found predecessor (first left child)
                        if(predecessor->_val == (val + _k + 1)) {
                            result = true;
                        }
                    }
                
                }
                
            }
            
            return result;
        }
    };
    
    int kEmptySlots(std::vector<int>& flowers, int k) {
        if( k < 0) return -1;
        BST bst(k);
        
        for(auto i = 0; i < flowers.size(); ++i)
        {
            if(bst.insert(flowers[i])) return i + 1;
        }
        
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    std::vector<int> flowers = {5,39,25,28,16,58,70,29,67,24,78,13,9,64,98,38,44,96,27,88,75,84,69,34,55,12,47,33,77,15,31,74,2,26,76,10,17,72,100,36,6,90,4,95,49,21,94,79,62,32,1,35,60,18,3,53,82,48,54,30,19,87,40,85,68,57,11,42,92,61,71,37,14,51,50,83,22,93,91,65,99,52,7,46,89,80,20,8,97,86,23,66,81,59,56,63,43,41,73,45};
    auto result = s.kEmptySlots(flowers, 4);
    std::cout << "Result: " << result << "\n";
    return 0;
}
