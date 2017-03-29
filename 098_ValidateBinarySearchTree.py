# 40.96%%
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        
        flagLeft, flagRight = False, False
        if not root.left:
            flagLeft = True
        else:
            temp = root.left
            while temp.right: temp = temp.right
            if temp.val < root.val and self.isValidBST(root.left):
                flagLeft = True
        if not flagLeft:
            return False
        if not root.right:
            flagRight = True
        else:
            temp = root.right
            while temp.left: temp = temp.left
            if temp.val > root.val and self.isValidBST(root.right):
                flagRight = True
        return flagRight
        
###Inorder traversal
class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.isBSTHelper(root, [])
        
    def isBSTHelper(self, root, prev=[]):
        if not root:
            return True
        if not self.isBSTHelper(root.left, prev):
            return False
        if not prev:
            prev.append(root.val)
        elif root.val <= prev[0]:
            return False
        prev[0] = root.val
        if not self.isBSTHelper(root.right, prev):
            return False
        return True
		
		
class Solution(object):
    def isValidBST(self, root, lessThan = float('inf'), largerThan = float('-inf')):
        if not root:
            return True
        if root.val <= largerThan or root.val >= lessThan:
            return False
        return self.isValidBST(root.left, min(lessThan, root.val), largerThan) and \
               self.isValidBST(root.right, lessThan, max(root.val, largerThan))
      
        

                              