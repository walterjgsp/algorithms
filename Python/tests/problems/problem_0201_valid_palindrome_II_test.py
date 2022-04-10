from unittest import TestCase

from Python.problems.problem_0201_valid_palidrome_II import Solution


class ValidPalindromeSolution(TestCase):
    def test_valid_palindrome(self):
        self.assertTrue(Solution.valid_palindrome("aba"))
        self.assertTrue(Solution.valid_palindrome("abca"))
        self.assertFalse(Solution.valid_palindrome("abc"))
