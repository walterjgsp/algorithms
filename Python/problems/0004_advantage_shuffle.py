# Problem Statement
# Given two arrays A and B of equal size, the advantage of A with
# respect to B is the number of indices i for which A[i] > B[i].
#
# Return any permutation of A that maximizes its advantage with respect to B.
from typing import List


def convert_to_list_of_dicts(list_to_convert: List) -> List[dict]:
    return [
        {
            'value': value,
            'index': index
        }
        for index, value in enumerate(list_to_convert)
    ]


class Solution:
    def advantageCount(self, A: List[int], B: List[int]) -> List[int]:
        result = [None] * len(A)

        b_helper = self.get_ordered_dict_list(B)
        A.sort()

        index_b = 0
        for a_index, a_value in enumerate(A):
            b_dict = b_helper[index_b]
            if a_value > b_dict['value']:
                result[b_dict['index']] = a_value
                A[a_index] = None
                index_b += 1

        none_result_index_list = [
            index for index, value in enumerate(result) if value is None
        ]

        for value in A:
            if value is not None:
                result[none_result_index_list.pop(0)] = value

        return result

    @staticmethod
    def get_ordered_dict_list(list_to_convert: List) -> List[dict]:
        result = convert_to_list_of_dicts(list_to_convert)
        result = sorted(result, key=lambda it: it['value'])
        return result


if __name__ == "__main__":
    # numsA = [2, 7, 11, 15]
    # numsB = [1, 10, 4, 11]
    numsA = [12, 24, 8, 32]
    numsB = [13, 25, 32, 11]
    solution = Solution()
    print(solution.advantageCount(numsA, numsB))
