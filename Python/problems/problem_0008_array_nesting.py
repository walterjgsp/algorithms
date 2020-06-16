"""
 Problem Statement

 A zero-indexed array A of length N contains all integers from 0 to N-1.
 Find and return the longest length of set S,
 where S[i] = {A[i], A[A[i]], A[A[A[i]]], ... } subjected to the rule below.

 Suppose the first element in S starts with the selection of element A[i]
 of index = i, the next element in S should be A[A[i]], and then A[A[A[i]]]…
 By that analogy, we stop adding right before a duplicate element occurs in S.

 Example:
 Input: A = [5,4,0,3,1,6,2]
 Output: 4
 Explanation:
 A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

 One of the longest S[K]:
 S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}

"""
from typing import List


def was_visited(value):
    return value < 0


def was_not_visited(value):
    return value >= 0


class Solution:
    @classmethod
    def array_nesting(cls, nums: List[int]) -> int:
        result = 0
        for index, _ in enumerate(nums):
            if was_visited(nums[index]):
                continue
            else:
                next_pos = nums[index]
                count = 0

                while nums[next_pos] != -1:
                    actual_pos = next_pos
                    next_pos = nums[next_pos]
                    count += 1
                    nums[actual_pos] = -1
                result = count if count > result else result

        return result
