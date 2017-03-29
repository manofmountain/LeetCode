# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
##61.64%
class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []
        s = [root]
        res = []
        while s:
            res.append(s[-1].val)
            node = s.pop()
            if node.right:
                s.append(node.right)
            if node.left:
                s.append(node.left)
        return res
        
##Morris  traversal
#18.68%
class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []
        res = list()
        curr = root
        while curr:
            if curr.left:
                predecessor = curr.left
                while predecessor.right and predecessor.right != curr:
                    predecessor = predecessor.right
                if not predecessor.right:
                    res.append(curr.val)
                    predecessor.right = curr
                    curr = curr.left
                else:
                    predecessor.right = None
                    curr = curr.right
            else:
                res.append(curr.val)
                curr = curr.right
        return res
            