# Problem Statement
# You are keeping score for a baseball game with strange rules.
# The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.

# At the beginning of the game, you start with an empty record.
# You are given a list of strings ops, where ops[i] is the ith operation you must apply to the record and is one of the following:

# An integer x - Record a new score of x.
# "+" - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.
# "D" - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.
# "C" - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.
# Return the sum of all the scores on the record.

from typing import List


class Solution:

    @staticmethod
    def cal_points(ops: List[str]) -> int:
        scores = []
        for operation in ops:
            if operation == 'C':
                scores.pop()
            elif operation == '+':
                scores.append(scores[-1]+scores[-2])
            elif operation == 'D':
                scores.append(scores[-1]*2)
            else:
                scores.append(int(operation))

        return sum(scores)
