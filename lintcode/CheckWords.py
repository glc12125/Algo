from typing import (
    List, Set
)

class Solution:
    """
    @param s: 
    @param str: 
    @return: Output whether this combination meets the condition
    """
    def check_word(self, s: str, str: List[str]) -> bool:
        # Write your code here
        if len(s) == 0:
            return True
        len_str = len(str)
        if len_str == 0:
            return False
        
        dictionary = set(str)
        #return self.check_combinations(s, dictionary)
        return self.check_combinations_bfs(s, dictionary)

    def check_combinations(self, s: str, str: Set[str]) -> bool:
        if len(s) == 1:
            return s in str
        if s not in str:
            return False

        for index in range(len(s)):
            if self.check_combinations(s[:index] + s[index+1:], str):
                return True
        return False

    def check_combinations_bfs(self, s: str, str: Set[str]) -> bool:
        queue = collections.deque([s])
        visited = set([s])
        while queue:
            word = queue.popleft()
            if word not in str:
                continue
            for i in range(len(word)):
                new_word = word[:i] + word[i+1:]
                if new_word == "":
                    return True
                if new_word in visited:
                    continue
                if new_word not in str:
                    continue
                queue.append(new_word)
                visited.add(new_word)
        return False



