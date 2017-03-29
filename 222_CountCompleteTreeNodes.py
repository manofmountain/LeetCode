# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
##26.74%
class Solution(object):
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        heightLeft = 1
        curr = root.left
        while curr:
            heightLeft += 1
            curr = curr.left
        return self.countNodesHelper(root, heightLeft)
    def countNodesHelper(self, root, heightLeft):
        if not root:
            return 0
        heightRight = 1
        curr = root.right
        while curr:
            heightRight += 1
            curr = curr.left
        return (1 << (heightLeft - 1)) + self.countNodesHelper(root.right, heightRight - 1) if heightLeft == heightRight else (1 << (heightRight - 1)) + self.countNodesHelper(root.left, heightLeft - 1)

public int countNodes(TreeNode root) {
    if (root == null)
        return 0;
    return 1 + countNodes(root.left) + countNodes(root.right)