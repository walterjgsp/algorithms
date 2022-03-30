from unittest import TestCase

from Python.problems.problem_0193_seach_2d_matrix import Solution


class Search2dMatrixSolution(TestCase):
    def test_when_target_exists_then_return_True(self):
        self.assertTrue(Solution.searchMatrix([[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]], 3))
        self.assertTrue(Solution.searchMatrix([[1]], 1))
        self.assertTrue(Solution.searchMatrix([[1, 3]], 3))

    def test_when_target_does_not_exist_then_return_False(self):
        self.assertFalse(Solution.searchMatrix([[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]], 13))
        self.assertFalse(Solution.searchMatrix([[4]], 1))
        self.assertFalse(Solution.searchMatrix([[1, 3]], 0))
