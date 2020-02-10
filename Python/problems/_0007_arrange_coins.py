# Problem Statement
#
# You have a total of n coins that you want to form in a staircase shape,
# where every k-th row must have exactly k coins.
#
# Given n, find the total number of full staircase rows that can be formed.
#
# n is a non-negative integer and fits within the range of a 32-bit signed integer.
# Example:
# n = 5
#
# The coins can form the following rows:
# ¤
# ¤ ¤
# ¤ ¤
# return 2.


class Solution:
    @staticmethod
    def arrange_coins(n: int) -> int:
        coins_per_roll = 0

        while n > coins_per_roll:
            coins_per_roll += 1
            n -= coins_per_roll

        return coins_per_roll
