from unittest import TestCase

from Python.problems._0007_arrange_coins import Solution


class ArrangeCoinsTestSolution(TestCase):
    def test_arrange_coins(self):
        n = 8
        expected_result = 3
        result = Solution.arrange_coins(n)
        self.assertEquals(expected_result, result)

