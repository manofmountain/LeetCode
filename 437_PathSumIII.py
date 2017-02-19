# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
# 25.84%
class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        if not root:
            return 0
        return self.pathSumHelper(root, sum) + self.pathSum(root.left, sum) + self.pathSum(root.right, sum)
    def pathSumHelper(self, root, sum):
        if not root:
            return 0
        count = 0
        if root.val == sum:
            count += 1
        return count + self.pathSumHelper(root.left, sum - root.val) + self.pathSumHelper(root.right, sum - root.val)