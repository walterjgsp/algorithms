# Problem Statement

# Write an efficient algorithm that searches for a value target in an m x n integer matrix.
# This matrix has the following properties:
#   Integers in each row are sorted from left to right.
#   The first integer of each row is greater than the last integer of the previous row.
from typing import List


class Solution:

    @staticmethod
    def search_matrix(matrix: List[List[int]], target: int) -> bool:

        if matrix[0][0] == target:
            return True

        # if the first item is higher than target, then target is not feasible
        if matrix[0][0] > target:
            return False

        # walk throught the first line
        for i in range(1, len(matrix)):
            if matrix[i][0] == target:
                return True
            if matrix[i][0] > target:
                return target in matrix[i-1]

        # check if it is the last column
        return target in matrix[len(matrix)-1]
