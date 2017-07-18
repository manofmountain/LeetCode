# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
##69.79%
class Solution(object):
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        minLeft, minRight = 0x7fffffff, 0x7fffffff
        if root.left:
            curr = root.left
            while curr.right: curr = curr.right
            minLeft = min(abs(root.val - curr.val), self.getMinimumDifference(root.left))
        if root.right:
            curr = root.right
            while curr.left: curr = curr.left
            minRight = min(abs(root.val - curr.val), self.getMinimumDifference(root.right))
        return min(minLeft, minRight)