# Definition for a undirected graph node
# class UndirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        def DFS(node):
            if not node: return node
            if node not in traced:
                traced[node] = UndirectedGraphNode(node.lable)
                for child in node.neighbors:
                    traced[node].neighbors.append(DFS(child))
            return traced[node]
        traced = dict()
        return DFS(node)
        