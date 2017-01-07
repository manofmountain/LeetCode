# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
# 94.2%
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        depthL = self.maxDepth(root.left)
        depthR = self.maxDepth(root.right)
        return depthL + 1 if depthL > depthR else depthR + 1
		
def maxDepth(self, root):
    return 1 + max(map(self.maxDepth, (root.left, root.right))) if root else 0