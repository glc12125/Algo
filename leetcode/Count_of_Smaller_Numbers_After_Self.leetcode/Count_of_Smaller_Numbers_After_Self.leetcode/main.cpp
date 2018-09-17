//
//  main.cpp
//  Count_of_Smaller_Numbers_After_Self.leetcode
//
//  Created by Liangchuan Gu on 11/12/2017.
//  Copyright © 2017 Liangchuan Gu. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
#include <iterator>


class Solution {
public:
    std::vector<int> countSmaller(std::vector<int>& nums) {
        std::multiset<int> holder;
        std::vector<int> result(nums.size());
        for(long i = nums.size() - 1; i >= 0; --i)
        {
            auto lower = holder.lower_bound(nums.at(i));
            result[i] = std::distance(holder.begin(), lower);
            holder.insert(nums.at(i));
        }
        
        return result;
    }

    struct Node {
        Node * _left;
        Node * _right;
        int _val;
        int _sum;
        int _dup;
        Node(int v, int s) : _val(v), _sum(s), _left(nullptr), _right(nullptr), _dup(1) {}
    };
    
    Node * insert(int num, Node* node, std::vector<int>& ans, int i, int preSum)
    {
        if (node == nullptr) {
            node = new Node(num, 0);
            ans[i] = preSum;
        } else if (node->_val == num) {
            node->_dup++;
            ans[i] = preSum + node->_sum;
        } else if (node->_val > num) {
            node->_sum++;
            node->_left = insert(num, node->_left, ans, i, preSum);
        } else {
            node->_right = insert(num, node->_right, ans, i, preSum + node->_dup + node->_sum);
        }
        return node;
    }

    std::vector<int> countSmaller1(std::vector<int>& nums) {
        size_t size_nums = nums.size();
        std::vector<int> ans(nums.size());
        Node * root = nullptr;
        for(long i = nums.size() - 1; i >= 0; --i)
        {
            root = insert(nums[i], root, ans, i, 0);
        }
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    std::vector<int> nums{-1, 0};
    auto result = s.countSmaller1(nums);
    for(auto item : result)
        std::cout << item << ", ";
    std::cout << std::endl;
    return 0;
}
