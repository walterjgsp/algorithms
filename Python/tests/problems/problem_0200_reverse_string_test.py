from unittest import TestCase

from Python.problems.problem_0200_reverse_string import Solution


class ReverseStringSolution(TestCase):
    def test_reverse_string(self):
        commonCase = {
            "input": ["h", "e", "l", "l", "o"],
            "expected": ["o", "l", "l", "e", "h"]
        }
        caseSenstiveCase = {
            "input": ["H", "a", "n", "n", "a", "h"],
            "expected": ["h", "a", "n", "n", "a", "H"]
        }

        Solution.reverse_string(commonCase["input"])
        self.assertEqual(commonCase["input"], commonCase["expected"])

        Solution.reverse_string(caseSenstiveCase["input"])
        self.assertEqual(caseSenstiveCase["input"], caseSenstiveCase["expected"])
