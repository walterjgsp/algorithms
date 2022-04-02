# Problem Statement
# Write a function to find the longest common prefix string amongst an array of strings.
# If there is no common prefix, return an empty string "".


class Solution:

    @staticmethod
    def longest_common_prefix(strs):
        if len(strs) == 0:
            return ""

        prefix = strs[0]

        for i in range(1, len(strs)):
            for index, character in enumerate(prefix):
                if(len(strs[i]) <= index):
                    prefix = strs[i]
                    break
                if character != strs[i][index]:
                    prefix = prefix[0:index]
                    break

        return prefix
