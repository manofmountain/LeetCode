# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
# 89.35%
class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if not root: return None
        if not p: return q
        if not q: return p
        max, min = p.val, q.val
        if max < min:
            max, min = q.val, p.val
        if root.val >= min and root.val <= max:
            return root
        elif root.val < min:
            return self.lowestCommonAncestor(root.right, p, q)
        else:
            return self.lowestCommonAncestor(root.left, p, q)
			
# A good non-Recursive way from LeetCode
def lowestCommonAncestor(self, root, p, q):
    while (root.val - p.val) * (root.val - q.val) > 0:
        root = (root.left, root.right)[p.val > root.val]
    return root
	
def lowestCommonAncestor(self, root, p, q):
    a, b = sorted([p.val, q.val])
    while not a <= root.val <= b:
        root = (root.left, root.right)[a > root.val]
    return root

def lowestCommonAncestor(self, root, p, q):
    while root:
        if p.val < root.val > q.val:
            root = root.left
        elif p.val > root.val < q.val:
            root = root.right
        else:
            return root
			
def lowestCommonAncestor(self, root, p, q):
    return root if (root.val - p.val) * (root.val - q.val) < 1 else \
           self.lowestCommonAncestor((root.left, root.right)[p.val > root.val], p, q)
		   
def lowestCommonAncestor(self, root, p, q):
    if p.val < root.val > q.val:
        return self.lowestCommonAncestor(root.left, p, q)
    if p.val > root.val < q.val:
        return self.lowestCommonAncestor(root.right, p, q)
    return root