'''
[[1,0,0,0,0],
 [0,1,0,0,1],
 [0,0,1,0,0],
 [0,0,0,1,0],
 [0,1,0,0,1]]
'''

from typing import (
    List,
)


NON_FRIEND, FRIEND = 0, 1


class Solution:
    """
    @param m: a matrix of integer
    @return: return an Integer
    """
    def find_circle_num(self, m: List[List[int]]) -> int:
        len_m = len(m)
        if len_m == 0:
            return 0

        visited = [False] * len_m
        friend_circles = 0
        for i in range(len_m):
            if not visited[i]:
                friend_circles += 1
                self.dfs(m, i, visited)
        return friend_circles

    def dfs(self, m: List[List[int]], i: int, visited: List[List[bool]]):
        for j in range(len(m)):
            if m[i][j] == FRIEND and not visited[j]:
                visited[j] = True
                self.dfs(m, j, visited)
