# Problem Statement

# You are given two non-empty linked lists representing two non-negative integers.
# The digits are stored in reverse order and each of their nodes contain a single digit.
# Add the two numbers and return it as a linked list.
#
# You may assume the two numbers do not contain any leading zero, except the number 0 itself.


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def populate_next_node(current_node: ListNode, value: int) -> ListNode:
    new_node = ListNode(value)
    current_node.next = new_node
    current_node = new_node
    return current_node


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        temp_head = ListNode(None)
        current_node = temp_head
        carry = 0

        while self.are_nodes_not_none(l1, l2):
            result_value, carry = self.calculate_result_and_carry(carry, l1, l2)
            current_node = populate_next_node(current_node, result_value)
            l1 = self.safely_get_next_node(l1)
            l2 = self.safely_get_next_node(l2)

        if carry:
            current_node.next = ListNode(carry)

        return temp_head.next

    def calculate_result_and_carry(self, carry: int, l1: ListNode, l2: ListNode) -> (int, int):
        l1_value = self.safely_extract_value_from_node(l1)
        l2_value = self.safely_extract_value_from_node(l2)
        result_total = l1_value + l2_value + carry
        result_value = int(result_total % 10)
        carry = int(result_total / 10)
        return result_value, carry

    @staticmethod
    def safely_get_next_node(node: ListNode) -> ListNode:
        return node.next if node is not None else None

    @staticmethod
    def are_nodes_not_none(l1: ListNode, l2: ListNode) -> bool:
        return l1 is not None or l2 is not None

    @staticmethod
    def safely_extract_value_from_node(node: ListNode) -> int:
        return node.val if node else 0


def linked_list_from_list(list_of_numbers: list) -> ListNode:
    temp_head = ListNode(None)
    current_node = temp_head
    for value in list_of_numbers:
        current_node = populate_next_node(current_node, value)
    return temp_head.next


def print_list_node(node: ListNode):
    while node is not None:
        print(f"{node.val}", end=" ")
        node = node.next
    print()


if __name__ == '__main__':
    first_list_of_numbers = [2, 4, 3]
    second_list_of_numbers = [5, 6, 4]
    first_list = linked_list_from_list(first_list_of_numbers)
    second_list = linked_list_from_list(second_list_of_numbers)
    solution = Solution()
    print_list_node(first_list)
    print_list_node(second_list)
    print_list_node(solution.addTwoNumbers(first_list, second_list))
