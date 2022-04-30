from unittest import TestCase

from Python.problems.problem_0194_find_duplicate_number import Solution


class FindDuplicateNumberSolution(TestCase):
    def test_find_duplicate(self):
        self.assertEqual(Solution.find_duplicate([1, 3, 4, 2, 2]), 2)
        self.assertTrue(Solution.find_duplicate([3, 1, 3, 4, 2]), 3)
