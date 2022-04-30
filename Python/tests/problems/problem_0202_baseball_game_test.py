from unittest import TestCase

from Python.problems.problem_0202_baseball_game import Solution


class BaseballGameSolution(TestCase):
    def test_cal_points(self):
        self.assertEqual(Solution.cal_points(["1"]), 1)
        self.assertEqual(Solution.cal_points(["5", "2", "C", "D", "+"]), 30)
        self.assertEqual(Solution.cal_points(["5", "-2", "4", "C", "D", "9", "+", "+"]), 27)
