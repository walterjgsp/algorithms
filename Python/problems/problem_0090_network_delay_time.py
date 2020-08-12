# Problem Statement
# There are N network nodes, labelled 1 to N.
#
# Given times, a list of travel times as directed edges times[i] = (u, v, w),
# where u is the source node, v is the target node, and w is the time it takes
# for a signal to travel from source to target.
#
# Now, we send a signal from a certain node K. How long will it take for all
# nodes to receive the signal? If it is impossible, return -1.
from heapq import heappush, heappop
from typing import List

INF = float('inf')


class Solution:

    @classmethod
    def network_delay_time(cls, times: List[List[int]], N: int, K: int) -> int:
        graph = mount_graph(N, times)
        calculated_times = cls._dijkstra(graph, K)
        result = max(calculated_times)
        if result == INF:
            result = -1
        return result

    @staticmethod
    def _dijkstra(graph, start_node):
        visited = set()
        time = [INF for node in graph]
        time[start_node - 1] = 0
        priority_queue = [(0, start_node)]

        while len(priority_queue) > 0:
            _, node = heappop(priority_queue)
            if node not in visited:
                visited.add(node)
                neighbours = sorted(graph[node - 1], key=lambda k: k[1])
                for neighbour in neighbours:
                    time[neighbour[0] - 1] = min(time[node - 1] + neighbour[1],
                                                 time[neighbour[0] - 1])
                    heappush(priority_queue,
                             (time[neighbour[0] - 1], neighbour[0]))
        return time


def mount_graph(number_of_nodes, edges):
    graph = initialize_graph_nodes(number_of_nodes)
    return fill_graph_edges(graph, edges)


def initialize_graph_nodes(number_of_nodes):
    graph = []
    for node in range(0, number_of_nodes):
        graph.append([])
    return graph


def fill_graph_edges(graph, edges):
    for edge in edges:
        graph[edge[0] - 1].append((edge[1:]))
    return graph
