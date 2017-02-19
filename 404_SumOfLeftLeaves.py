# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
# 4.07%
class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        res = 0
        if root.left and not root.left.left and not root.left.right:
            res = root.left.val
        return res + self.sumOfLeftLeaves(root.left) + self.sumOfLeftLeaves(root.right)
        
        