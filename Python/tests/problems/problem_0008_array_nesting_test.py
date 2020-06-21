from unittest import TestCase

from Python.problems.problem_0008_array_nesting import Solution


class ArrangeCoinsTestSolution(TestCase):
    def setUp(self) -> None:
        self.nums_list = [
           [5, 4, 0, 3, 1, 6, 2],
           [0, 1, 2],
           [0, 2, 1]
        ]
        self.expected_result_list = [4, 1, 2]

    def test_array_nesting(self):
        for index, expected_result in enumerate(self.expected_result_list):
            result = Solution.array_nesting(self.nums_list[index])
            self.assertEquals(expected_result, result)
