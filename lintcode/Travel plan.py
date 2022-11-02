from typing import (
    List, Set
)

class Solution:
    """
    @param arr: the distance between any two cities
    @return: the minimum distance Alice needs to walk to complete the travel plan
    """
    def travel_plan(self, arr: List[List[int]]) -> int:
        # Write your code here.
        len_cities = len(arr)
        if len_cities == 0:
            return 0
        self.min_distance = sys.maxsize

        self.search(arr, 0, set([0]), 0, [])

        return self.min_distance

    def search(self, arr: List[List[int]], city: int, visited: Set, distance: int, path: List[int]):
        if city == 0 and 1 < len(visited) < len(arr):
            return
        if len(visited) == len(arr) or len(path) > len(arr) + 1:
            if city == 0 and distance < self.min_distance:
                self.min_distance = distance
            return
        if distance > self.min_distance:
            return


        for next_city in range(0, len(arr[city])):
            if next_city == city:
                continue
            if next_city in visited and next_city != 0:
                continue
            visited.add(next_city)
            self.search(arr, next_city, visited, distance + arr[city][next_city], path + [next_city])
            visited.remove(next_city)
