from unittest import TestCase

from Python.problems.problem_0199_longest_common_prefix import Solution


class FindDuplicateNumberSolution(TestCase):
    def test_find_duplicate(self):
        self.assertEqual(Solution.longest_common_prefix(["flower", "flow", "flight"]), "fl")
        self.assertEqual(Solution.longest_common_prefix(["dog", "racecar", "car"]), "")
