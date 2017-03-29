
##40.2%
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        def preOrderBuilding(curr, level):
            if len(res) == level:
                res.append([])
            res[level].append(curr.val)
            if curr.left: preOrderBuilding(curr.left, level + 1)
            if curr.right: preOrderBuilding(curr.right, level + 1)
            
        res = list()
        if not root: return res
        preOrderBuilding(root, 0)
        for i in xrange(1, len(res), 2):
            res[i].reverse()
        return res
        
        