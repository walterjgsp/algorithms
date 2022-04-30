from unittest import TestCase

from Python.problems.problem_0168_backspace_compare import Solution


class TestBackspaceCompareSolution(TestCase):
    def test_backspace_compare(self):
        self.assertTrue(Solution.backspace_compare("ab#c", "ad#c"))
        self.assertFalse(Solution.backspace_compare("a#c", "b"))
        self.assertTrue(Solution.backspace_compare("ab##", "c#d#"))
        self.assertTrue(Solution.backspace_compare("y#fo##f", "y#f#o##f"))
        self.assertTrue(Solution.backspace_compare("a##c", "#a#c"))
