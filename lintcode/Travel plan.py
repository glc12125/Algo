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

    def travelPlan_dp(self, arr):
        # Write your code here.
        n = len(arr)
        dp = [
          [float('inf')] * n
          for _ in range(1 << n)
        ]

        dp[1][0] = 0

        for state in range(1 << n):
          for i in range(1, n):
            if state & (1 << i) == 0:
              continue
            prev_ = state ^ (1 << i)
            for j in range(n):
              if prev_ & (1 << j) == 0:
                continue
              dp[state][i] = min(dp[state][i], dp[prev_][j] + arr[j][i])

        result = float('inf')
        # print(dp)
        for last in range(1, n):
          result = min(result, dp[(1 << n) - 1][last] + arr[last][0])
        return result
