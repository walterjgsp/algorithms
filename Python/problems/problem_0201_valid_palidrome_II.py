# Problem Statement
# Given a string s, return true if the s can be palindrome after deleting at most one character from it.

class Solution:

    @classmethod
    def valid_palindrome(cls, s: str) -> bool:
        left = 0
        right = len(s)-1

        # check if is palindrome until finds a mismatched pair of characters
        while left < right:
            if s[left] != s[right]:
                # check if is a palindrome by skipping one of the mismatched characters
                return cls._is_palindrome(s, left+1, right) or cls._is_palindrome(s, left, right-1)
            left += 1
            right -= 1

        return True

    @classmethod
    def _is_palindrome(cls, s: str, left: int, right: int) -> bool:
        while left < right:
            if s[left] != s[right]:
                return False
            left += 1
            right -= 1
        return True
