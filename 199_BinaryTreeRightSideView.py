# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#76.23%
class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        def rightSideHelper(node, level):
            if not node: return
            if level == len(res):
                res.append(node.val)
            rightSideHelper(node.right, level + 1)
            rightSideHelper(node.left, level + 1)
        res = []
        rightSideHelper(root, 0)
        return res

#46.79%       
class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root: return []
        queue = [root]
        res = []
        while queue:
            res.append(queue[0].val)
            size = len(queue)
            for i in xrange(size):
                node = queue[0]
                if node.right: queue.append(node.right)
                if node.left: queue.append(node.left)
                del queue[0]
        return res
                