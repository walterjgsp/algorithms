# Problem Statement
#
# Given an array of integers, return indices of the two numbers such that they add up to a specific target.
#
# You may assume that each input would have exactly one solution, and you may not use the same element twice.
from typing import List


class Solution:
    @classmethod
    def two_sum(cls, nums: List[int], target: int) -> List[int]:
        known_items = {}
        for index, item in enumerate(nums):
            try:
                desired_item_index = known_items[target - item]
                return [desired_item_index, index]
            except KeyError:
                known_items[item] = index
        return [0, 0]


if __name__ == '__main__':
    input_nums = [2, 7, 11, 15]
    input_target = 9
    print(str(Solution.two_sum(input_nums, input_target)))
