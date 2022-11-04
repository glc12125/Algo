"""
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
"""
from typing import (
    List, Dict
)
from lintcode import (
    TreeNode,
)

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

class Solution:
    """
    @param root: a root of integer
    @return: return a integer list
             we will sort your return value in output
    """
    def find_mode(self, root: TreeNode) -> List[int]:
        # write your code here
        if root is None:
            return []

        #counter = {}
        counter = collections.defaultdict(int)

        self.search_modes(root, counter)

        sorted_by_frequencies = sorted(counter.items(), key = lambda x:x[1], reverse=True)
        most_frequent = sorted_by_frequencies[0][1]
        results = []
        for val, frequency in sorted_by_frequencies:
            if frequency == most_frequent:
                results.append(val)

        return results

    def search_modes(self, root: TreeNode, counter: Dict):
        if root is None:
            return

        #counter.update({root.val: counter.get(root.val, 0) + 1})
        counter[root.val] += 1

        self.search_modes(root.left, counter)
        self.search_modes(root.right, counter)