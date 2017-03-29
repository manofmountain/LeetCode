##99.21%
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        if not postorder:
            return None
        
        size = len(postorder)
        curr = root = TreeNode(postorder[size - 1])
        s = [curr]
        iIndex, pIndex = size - 1, size - 2
        while pIndex >= 0:
            if curr.val != inorder[iIndex]:
                curr.right = TreeNode(postorder[pIndex])
                curr = curr.right
                s.append(curr)
            else:
                while s and s[-1].val == inorder[iIndex]:
                    curr, iIndex = s[-1], iIndex - 1
                    s.pop()
                curr.left = TreeNode(postorder[pIndex])
                curr = curr.left
                s.append(curr)
            pIndex -= 1
        return root