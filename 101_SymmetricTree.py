# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
# 35.68%
class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def isSymmetricHelper(treeLeft, treeRight):
            if treeLeft is not None and treeRight is not None:
                if treeLeft.val != treeRight.val:
                    return False
                else:
                    return isSymmetricHelper(treeLeft.left, treeRight.right) and isSymmetricHelper(treeLeft.right, treeRight.left)
            else:
                return treeLeft is treeRight
                
        return root is None or isSymmetricHelper(root.left, root.right)
		
# An iterative solution from LeetCode
def isSymmetric(self, root):
    now = []
    if root:
        now.append(root)
    while now:
        vals = []
        for i in now:
            if i:
                vals.append(i.val)
            else:
                vals.append(None)
        if list(reversed(vals)) != vals:
            return False
        else:
            now = [j for i in now if i for j in (i.left, i.right)]
    return True

def isSymmetric(self, root):
    def tuple_tree(root):
        return root and (root.val, tuple_tree(root.left), tuple_tree(root.right))

    def reverse_tree(root):
        if root:
            root.right, root.left = reverse_tree(root.left), reverse_tree(root.right)
        return root
        
    return tuple_tree(root) == tuple_tree(reverse_tree(root))

# This solution looks like mine, but more 'python style' than mine	
def isSymmetric(self, root):
    def sym_tree(L,R):
        if L and R: 
            return L.val == R.val and sym_tree(L.left, R.right) and sym_tree(L.right, R.left)
        else:
            return L == R
    return sym_tree(root, root)