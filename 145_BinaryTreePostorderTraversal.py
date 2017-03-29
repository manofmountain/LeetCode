# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return list()
        curr = root
        res = list()
        s = list()
        while s or curr:
            if not curr:
                curr = s.pop()
            if curr.left:
                lchild, curr.left = curr.left, None
                s.append(curr)
                curr = lchild
            elif curr.right:
                rchild, curr.right = curr.right, None
                s.append(curr)
                curr = rchild
            else:
                res.append(curr.val)
                curr = None
        return res