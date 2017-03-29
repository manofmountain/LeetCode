#99.28%
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if not preorder:
            return None
        root = curr = TreeNode(preorder[0])
        stack = [curr]
        index = 0
        for i in xrange(1, len(preorder)):
            if curr.val != inorder[index]:
                curr.left = TreeNode(preorder[i])
                curr = curr.left
                stack.append(curr)
            else:
                while len(stack) != 0 and stack[-1].val == inorder[index]:
                    curr = stack[-1]
                    stack.pop()
                    index += 1
                curr.right = TreeNode(preorder[i])
                curr = curr.right
                stack.append(curr)
        return root