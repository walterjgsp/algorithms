# Problem Statement
# Write a function that reverses a string. The input string is given as an array of characters s.
# You must do this by modifying the input array in-place with O(1) extra memory.
from typing import List


class Solution:

    @staticmethod
    def reverse_string(s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        for index in range(0, len(s)//2):
            temp = s[index]
            s[index] = s[-index-1]
            s[-index-1] = temp
