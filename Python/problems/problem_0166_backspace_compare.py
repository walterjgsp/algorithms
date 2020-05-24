# Problem Statement

# Given two strings s and t, return if they are equal when both are typed into empty text editors.
# "#" means a backspace character.
# Note that after backspacing an empty text, the text will continue empty.


class Solution:
    @staticmethod
    def backspace_compare(s: str, t: str) -> bool:
        return generate_final_string(s) == generate_final_string(t)


def generate_final_string(raw_input: str) -> str:
    result = ''
    for character in raw_input:
        # python string indexing will handle the empty string case
        if character == '#':
            result = result[:-1]
        else:
            result += character
    return result
