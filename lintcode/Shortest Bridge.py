'''
In a given 2D binary array A, there are two islands. (An island is a 4-directionally connected group of 1s not connected to any other 1s.)

Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.

Return the smallest number of 0s that must be flipped. (It is guaranteed that the answer is at least 1.)
'''
from typing import (
    List, Set
)

ISLAND, WATER = 1, 0

DIRECTIONS = [(0, 1), (0, -1), (1, 0), (-1, 0)]

class Solution:
    """
    @param a:
    @return:
    """
    def shortest_bridge(self, a: List[List[int]]) -> int:
        len_row = len(a)
        if len_row == 0:
            return 0
        len_col = len(a[0])
        if len_col == 0:
            return 0

        visited = set()
        islands = []
        for row in range(len(a)):
            for col in range(len(a[0])):
                if (row, col) not in visited and a[row][col] == ISLAND:
                    visited_one_pass = set([(row, col)])
                    self.search_islands(a, row, col, visited_one_pass)
                    #print("visited_one_pass: {}".format(visited_one_pass))
                    visited |= visited_one_pass
                    #print("visited: {}".format(visited))
                    islands.append(visited_one_pass)

        if len(islands) != 2:
            print("Incorrect setup! Only 2 islands supported")
            exit(-1)

        island_from, island_to = islands[0], islands[1]
        #print("island_from: {}".format(island_from))
        #print("island_to: {}".format(island_to))
        return self.find_bridge_bfs(a, island_from, island_to)

    def find_bridge_bfs(self, a: List[List[int]], island_from: Set, island_to: Set) -> int:
        queue = collections.deque([(node, 0) for node in island_from])
        visited = set(island_from)
        while queue:
            node, distance = queue.popleft()
            if node in island_to:
                return distance - 1
            for delta_row, delta_col in DIRECTIONS:
                next_row = node[0] + delta_row
                next_col = node[1] + delta_col
                if not self.valid(a, next_row, next_col):
                    continue
                if (next_row, next_col) not in visited:
                    queue.append(((next_row, next_col), distance + 1))
                    visited.add((next_row, next_col))

    def search_islands(self, a: List[List[int]], row: int, col: int, visited_one_pass: Set):

        for delta_row, delta_col in DIRECTIONS:
            next_row = row + delta_row
            next_col = col + delta_col
            if (next_row, next_col) in visited_one_pass:
                continue
            if not self.valid(a, next_row, next_col):
                continue
            if a[next_row][next_col] == WATER:
                continue
            visited_one_pass.add((next_row, next_col))
            self.search_islands(a, next_row, next_col, visited_one_pass)


    def shortest_bridge_timedout(self, a: List[List[int]]) -> int:
        len_row = len(a)
        if len_row == 0:
            return 0
        len_col = len(a[0])
        if len_col == 0:
            return 0

        self.counter_flip = sys.maxsize
        self.flip(a, 0)

        return self.counter_flip

    def flip(self, a: List[List[int]], counter: int):
        if self.is_island_connected(a):
            self.counter_flip = min(self.counter_flip, counter)
            return


        for row in range(len(a)):
            for col in range(len(a[0])):
                if a[row][col] == WATER:
                    a[row][col] = ISLAND
                    self.flip(a, counter + 1)
                    a[row][col] = WATER

    def is_island_connected(self, a: List[List[int]])->bool:
        len_row = len(a)
        len_col = len(a[0])

        visited = [[False] * len_col for _ in range(len_row)]

        counter = 0
        for row in range(len_row):
            for col in range(len_col):
                if a[row][col] == ISLAND and not visited[row][col]:
                    self.bfs(a, row, col, visited)
                    counter += 1
        return counter == 1

    def bfs(self, a: List[List[int]], row: int, col: int, visited: List[List[bool]]):

        queue = collections.deque([(row, col)])
        visited[row][col] = True
        while queue:
            cur_row, cur_col = queue.popleft()
            for delta_row, delta_col in DIRECTIONS:
                next_row = cur_row + delta_row
                next_col = cur_col + delta_col
                if not self.valid(a, next_row, next_col):
                    continue
                if a[next_row][next_col] == WATER:
                    continue
                if visited[next_row][next_col]:
                    continue
                queue.append((next_row, next_col))
                visited[next_row][next_col] = True

    def valid(self, a: List[List[int]], row: int, col: int) -> bool:
        return 0 <= row < len(a) and 0 <= col < len(a[0])