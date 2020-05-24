from unittest import TestCase

from Python.problems.problem_0004_advantage_shuffle import Solution


class AdvantageShuffleTestSolution(TestCase):
    def testAdvantageShuffle_(self):
        list_a = [2, 7, 11, 15]
        list_b = [1, 10, 4, 11]
        expected_result = [2, 11, 7, 15]
        solution = Solution()
        result = solution.advantage_count(list_a, list_b)
        self.assertListEqual(expected_result, result)
