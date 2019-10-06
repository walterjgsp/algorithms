from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        known_items = {}
        for index, item in enumerate(nums):
            try:
                desired_item_index = known_items[target - item]
                return [desired_item_index, index]
            except KeyError:
                known_items[item] = index
        return [0, 0]


if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 9
    solution = Solution()
    print(str(solution.twoSum(nums, target)))
