from unittest import TestCase

from Python.problems._0001_two_sum import Solution


class TwoSumTestSolution(TestCase):

    def test_two_sum_has_result(self):
        self.assertListEqual(Solution.two_sum([2, 11, 7, 15], 9), [0, 2])
        self.assertListEqual(Solution.two_sum([1, 5, 6, 7, 1, 4, 2, 11, 7, 15], 9), [1, 5])

    def test_two_sum_without_result(self):
        """
        Leet Code doesn't define the behavior when the solution isn't possible and unique
        The chosen behavior here is to return an [0, 0] list
        """
        self.assertListEqual(Solution.two_sum([2, 11, 7, 15], 10), [0, 0])
        self.assertListEqual(Solution.two_sum([], 9), [0, 0])
        self.assertListEqual(Solution.two_sum([2], 2), [0, 0])

