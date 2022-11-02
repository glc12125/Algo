'''
There is a tree of nn nodes with Num.00 to n-1n−1, where node 00 is the root node and the parent node of node ii is father[i]father[i]. Now to water the tree, sprinkle water on the root node, the water will flow down every edge, from the father of node ii to node ii costs time[i]time[i], how long will it take to flow water to all nodes?
'''
from typing import (
    List, Dict, Set
)

class Solution:
    """
    @param father: the father of every node
    @param time: the time from father[i] to node i
    @return: time to flower tree
    """
    def time_to_flower_tree(self, father: List[int], time: List[int]) -> int:
        # write your code here
        max_time = 0
        cache = {}
        for i in range(1, len(father)):
            this_time = self.search(father, time, cache, i)
            max_time = max(max_time, this_time)

        return max_time

    def search(self, father: List[int], time: List[int], cache: Dict, node: int):
        if node == 0:
            return 0

        if node in cache:
            return cache[node]

        cache[node] = time[node] + self.search(father, time, cache, father[node])

        return cache[node]


    def time_to_flower_tree(self, father: List[int], time: List[int]) -> int:
        # write your code here

        graph = self.build_graph(father)

        queue = collections.deque([(0, 0)])
        max_time = 0
        while queue:
            node, current_time = queue.popleft()
            max_time = max(max_time, current_time)
            for son in graph[node]:
                queue.append((son, current_time + time[son]))

        return max_time

    def build_graph(self, father: List[int]) -> Dict:
        graph = collections.defaultdict(set)

        for i in range(len(father)):
            graph[father[i]].add(i)
        return graph