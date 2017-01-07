# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
# 78.37%
class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def heightBalanced(root):
            if not root:
                return 0, True
            heightL, flagL = heightBalanced(root.left)
            heightR, flagR = heightBalanced(root.right)
            if flagL and flagR and abs(heightL - heightR) <= 1:
                return max(heightL, heightR) + 1, True
            return 0, False
        
        if not root:
            return True
        heightL, flagL = heightBalanced(root.left)
        heightR, flagR = heightBalanced(root.right)
        if flagL and flagR and abs(heightL - heightR) <= 1:
            return True    
        return False