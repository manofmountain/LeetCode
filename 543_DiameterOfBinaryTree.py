# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
##38.6%
class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def helper(curr):
            if not curr:
                return 0, 0
            resLeft, hLeft = helper(curr.left)
            resRight, hRight = helper(curr.right)
            res = max([resLeft, resRight, hLeft + hRight])
            h = max(hLeft, hRight) + 1
            return res, h
        return helper(root)[0]
		
def diameterOfBinaryTree(self, root):
    self.best = 1
    def depth(root):
        if not root: return 0
        ansL = depth(root.left)
        ansR = depth(root.right)
        self.best = max(self.best, ansL + ansR + 1)
        return 1 + max(ansL, ansR)
        
    depth(root)
    return self.best - 1
	
class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.ans = 0
        
        def depth(p):
            if not p: return 0
            left, right = depth(p.left), depth(p.right)
            self.ans = max(self.ans, left+right)
            return 1 + max(left, right)
            
        depth(root)
        return self.ans
                