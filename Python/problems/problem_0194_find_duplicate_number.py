# Problem Statement

# Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
# There is only one repeated number in nums, return this repeated number.
from typing import List


class Solution:

    @staticmethod
    def find_duplicate(nums: List[int]) -> int:
        
        known = set()
        
        for _, value in enumerate(nums):
            if value in known:
                return value
            
            known.add(value)
