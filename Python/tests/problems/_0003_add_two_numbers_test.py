from unittest import TestCase
from typing import List
from Python.problems._0003_add_two_numbers import Solution, linked_list_from_list, list_from_linked_list


class AddTwoNumbersTestSolution(TestCase):

    @classmethod
    def _calculate(cls, first_list: List, second_list: List) -> List:
        first_linked_list = linked_list_from_list(first_list)
        second_linked_list = linked_list_from_list(second_list)

        solution = Solution()
        result = solution.addTwoNumbers(first_linked_list, second_linked_list)
        return list_from_linked_list(result)

    def testAddTwoNumbers(self):
        first_list = [2, 4, 3]
        second_list = [5, 6, 4]
        expected_result = [7, 0, 8]
        result_as_list = self._calculate(first_list, second_list)
        self.assertListEqual(expected_result, result_as_list)
