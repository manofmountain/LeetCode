###83.91%

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        def pathSumHelper(root, sum):
            if not root:
                return
            curr.append(root.val)
            if root.val == sum and not root.left and not root.right:
                res.append(curr[:])
                curr.pop()
                return
            pathSumHelper(root.left, sum - root.val)
            pathSumHelper(root.right, sum - root.val)
            curr.pop()
        res = list()
        curr = list()
        pathSumHelper(root, sum)
        return res
		
		
class Solution:

def pathSum(self, root, sum):
    if not root: return []
    if root.left == None and root.right == None:
        if sum == root.val: 
            return \[\[root.val\]\]
        else: 
            return []
    a = self.pathSum(root.left, sum - root.val) + \
        self.pathSum(root.right, sum - root.val)
    return [[root.val] + i for i in a]