# 17.27%
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        def constructTree(rootVal, nodeLeft, nodeRight):
            root = TreeNode(rootVal)
            root.left, root.right = nodeLeft, nodeRight
            return root
        def generateTreesHelper(start, end):
            if start > end:
                return [None]
            if start == end:
                return [TreeNode(start)]
            return [constructTree(rootVal, nodeLeft, nodeRight) for rootVal in xrange(start, end + 1) for nodeLeft in generateTreesHelper(start, rootVal - 1) for nodeRight in generateTreesHelper(rootVal + 1, end)]
                
        if n <= 0:
            return []
        return generateTreesHelper(1, n)
        