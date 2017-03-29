# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
##62.99%
class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        def cntOfBST(node):
            if not node:
                return 0
            return 1 + cntOfBST(node.left) + cntOfBST(node.right)
        if not root:
            return 0
        cntLeft =  cntOfBST(root.left)
        if cntLeft == k - 1:
            return root.val
        elif cntLeft > k - 1:
            return self.kthSmallest(root.left, k)
        else:
            return self.kthSmallest(root.right, k - cntLeft - 1)
			
##Inorder solution			
class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        count = []
        self.helper(root, count)
        return count[k-1]
        
    def helper(self, node, count):
        if not node:
            return
        
        self.helper(node.left, count)
        count.append(node.val)
        self.helper(node.right, count)
