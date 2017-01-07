# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
# 17.18%
class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        ans, level = [], [root]
        while root and level:
            ans.append([node.val for node in level])
            level = [node for tree in level for node in (tree.left, tree.right) if node]
        return ans[::-1]