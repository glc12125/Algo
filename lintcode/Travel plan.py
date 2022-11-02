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

        self.search(arr, 0, set([0]), 0)

        return self.min_distance

    def search(self, arr: List[List[int]], city: int, visited: Set, distance: int):

        if len(visited) == len(arr):
            distance += arr[city][0]
            if distance < self.min_distance:
                self.min_distance = distance
            return
        if distance > self.min_distance:
            return


        for next_city in range(1, len(arr[city])):
            if next_city == city:
                continue
            if next_city in visited:
                continue
            visited.add(next_city)
            self.search(arr, next_city, visited, distance + arr[city][next_city])
            visited.remove(next_city)
