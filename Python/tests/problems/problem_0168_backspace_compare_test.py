from unittest import TestCase

from Python.problems.problem_0168_backspace_compare import Solution


class TestBackspaceCompareSolution(TestCase):
    def test_backspace_compare(self):
        self.assertEquals(Solution.backspace_compare("ab#c", "ad#c"), True)
        self.assertEquals(Solution.backspace_compare("a#c", "b"), False)
        self.assertEquals(Solution.backspace_compare("ab##", "c#d#"), True)
        self.assertEquals(Solution.backspace_compare("y#fo##f", "y#f#o##f"), True)
        self.assertEquals(Solution.backspace_compare("a##c", "#a#c"), True)
