# Problem Statement
#
# Given the root of a binary tree, then value v and depth d, you need to add a
# row of nodes with value v at the given depth d. The root node is at depth 1.
#
# The adding rule is: given a positive integer depth d, for each NOT null tree
# nodes N in depth d-1, create two tree nodes with value v as N's left subtree
# root and right subtree root. And N's original left subtree should be the left
# subtree of the new left subtree root, its original right subtree should be the
# right subtree of the new right subtree root. If depth d is 1 that means there
# is no depth d-1 at all, then create a tree node with value v as the new root
# of the whole original tree, and the original tree is the new root's left subtree.
# //
# Example:
#        4               4
#      /   \           /   \
#     2     6   =>   1      1
#    / \   /        /        \
#   3   1 5        2          6
#                /  \        /
# v = 1        3     1      5
# d = 2


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def addOneRow(self, root: TreeNode, v: int, d: int) -> TreeNode:
        if d == 1:
            node = TreeNode(v)
            node.left = root
            return node
        if d == 2:
            add_left(v, root)
            add_right(v, root)
        else:
            if root.left is not None:
                self.addOneRow(root.left, v, d - 1)
            if root.right is not None:
                self.addOneRow(root.right, v, d - 1)
        return root


def add_left(v: int, root: TreeNode):
    node_left = TreeNode(v)
    node_left.left = root.left
    root.left = node_left


def add_right(v: int, root: TreeNode):
    node_right = TreeNode(v)
    node_right.right = root.right
    root.right = node_right
