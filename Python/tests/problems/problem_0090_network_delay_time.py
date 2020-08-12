from unittest import TestCase

from Python.problems.problem_0090_network_delay_time import Solution


class NetworkDelayTimeTestSolution(TestCase):

    def setUp(self) -> None:
        self.simple_graph = _mount_simple_graph()
        self.two_way_graph = _mount_two_way_graph()
        self.impossible_graph = _mount_impossible_graph()

    def test_simple_graph(self):
        result = Solution.network_delay_time(self.simple_graph['times'],
                                             self.simple_graph['nodes'],
                                             self.simple_graph['start'])
        self.assertEquals(2, result)

    def test_two_way_graph(self):
        result = Solution.network_delay_time(self.two_way_graph['times'],
                                             self.two_way_graph['nodes'],
                                             self.two_way_graph['start'])
        self.assertEquals(59, result)

    def test_impossible_graph(self):
        result = Solution.network_delay_time(self.impossible_graph['times'],
                                             self.impossible_graph['nodes'],
                                             self.impossible_graph['start'])
        self.assertEquals(-1, result)


def _mount_simple_graph():
    return {
        'times': [[2, 1, 1], [2, 3, 1], [3, 4, 1]],
        'nodes': 4,
        'start': 2
    }


def _mount_two_way_graph():
    return {
        'times': [
            [4, 2, 76], [1, 3, 79], [3, 1, 81], [4, 3, 30], [2, 1, 47],
            [1, 5, 61], [1, 4, 99], [3, 4, 68], [3, 5, 46], [4, 1, 6],
            [5, 4, 7], [5, 3, 44], [4, 5, 19], [2, 3, 13], [3, 2, 18],
            [1, 2, 0], [5, 1, 25], [2, 5, 58], [2, 4, 77], [5, 2, 74]
        ],
        'nodes': 5,
        'start': 3
    }


def _mount_impossible_graph():
    return {
        'times': [[1, 2, 1]],
        'nodes': 2,
        'start': 2
    }
